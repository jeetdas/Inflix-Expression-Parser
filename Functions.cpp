#include "Functions.h"
#include <iostream>

using namespace std;

infixParser::infixParser()
{
	expn = "";
	answer = -1;
	error = false;
}
infixParser::infixParser(string str)
{
	expn = str;
}
void infixParser::setAnswer(double ans)
{
	answer = ans;
}
double infixParser::getAnswer()
{
	try
	{
		expn = removeSpaces(expn);
	}
	catch (const char* eMsg)
	{
		error = true;
		cerr << eMsg << endl;
	}
	expn = reduceExpression(expn);
	if (!error)
		answer = processedAnswer(expn);
	if (!error)
		return answer;
	return -1;
}
void infixParser::setExpn(string str)
{
	expn = str;
}
string infixParser::getExpn()
{
	return expn;
}
string infixParser::removeSpaces(string str)
{
	string::iterator it, it_copy_prev, it_copy_next;
	int count = 1;
	for (it = str.begin(); it < str.end(); ++it, ++count)
	{
		if (*it == ' ')
		{
			it_copy_prev = it;
			it_copy_next = it;
			--it_copy_prev;
			++it_copy_next;
			if (isdigit(*(it_copy_prev)) && isdigit(*(it_copy_next)))
			{
				string errorMsg = "Two operands in a row @ char " + to_string(count);
				throw errorMsg.c_str();
			}
			else
			{
				str.erase(count - 1, 1);
			}
		}
	}
	return str;
}
int infixParser::precedenceOfOperator(char op)
{
	switch (op)
	{
	case '!':
	case PLUS: // ++
	case MINUS: // --
	case NEGATIVE: // +2
		return 8;
	case '^':
		return 7;
	case '*':
	case '/':
	case '%':
		return 6;
	case '+':
	case '-':
		return 5;
	case '>':
	case GREATEREQUAL: // >=
	case '<':
	case LESSEQUAL: // <=
		return 4;
	case EQUAL: // ==
	case NOTEQUAL: // !=
		return 3;
	case LOGICALAND: // &&
		return 2;
	case LOGICALOR: // ||
		return 1;
	default:
		return 0; // Error case
	}
}
string infixParser::reduceExpression(string str)
{
	string proccessedString = "";
	char temp;
	string::iterator it;
	for (it = str.begin(); it < str.end(); ++it)
	{
		if (isdigit(*it))
		{
			proccessedString += *it;
		}
		else
		{
			temp = *(++it);
			//cout << "T = " << temp << endl;
			--it;
			if (!(isdigit(temp)))
			{
				if (temp == *it)
				{
					switch (temp)
					{
					case '+':
						proccessedString += PLUS;
						++it;
						break;
					case '-':
						proccessedString += MINUS;
						++it;
						break;
					case '&':
						proccessedString += LOGICALAND;
						++it;
						break;
					case '|':
						proccessedString += LOGICALOR;
						++it;
						break;
					case '=':
						proccessedString += EQUAL;
						++it;
						break;
					}
				}
				else if (temp == '=')
				{
					switch (*it)
					{
					case '>':
						proccessedString += GREATEREQUAL;
						++it;
						break;
					case '<':
						proccessedString += LESSEQUAL;
						++it;
						break;
					case '!':
						proccessedString += NOTEQUAL;
						++it;
						break;
					}
				}
				else
				{
					proccessedString += *it;
				}
			}
			else
			{
				proccessedString += *it;
			}
		}
	}
	proccessedString = "(" + proccessedString + ")";

	return proccessedString;
}
double infixParser::processedAnswer(string expn)
{
	double answer = 0.0;
	char *tempPtr;
	char temp;
	double temp2, n1, n2;
	bool addToNumberStack = true;
	string::iterator it;
	for (it = expn.begin(); it < expn.end(); ++it)
	{
		if (!(isdigit(*it)))
		{
			if (operatorsStack.empty() || (precedenceOfOperator(*it) >= precedenceOfOperator(operatorsStack.top())) || *it == '(')
			{
				operatorsStack.push(*it);
			}
			else if (*it == ')')
			{
				while (operatorsStack.top() != '(')
				{
					n2 = numbersStack.top();
					numbersStack.pop();
					n1 = numbersStack.top();
					numbersStack.pop();
					try {
						temp2 = calculate(n1, operatorsStack.top(), n2);
					}
					catch (const char* msg) {
						error = true;
						cerr << msg << endl;
					}
					operatorsStack.pop();
					numbersStack.push(temp2);
				}
				operatorsStack.pop();
			}
			else
			{
				while (precedenceOfOperator(*it) < precedenceOfOperator(operatorsStack.top()))
				{
					switch (operatorsStack.top())
					{
					case '!':
					case PLUS:
					case MINUS:
					case NEGATIVE:
						n1 = numbersStack.top();
						numbersStack.pop();
						temp2 = calculate(n1, operatorsStack.top());
						operatorsStack.pop();
						numbersStack.push(temp2);
						break;
					case '^':
					case '*':
					case '/':
					case '%':
					case '+':
					case '-':
					case '>':
					case GREATEREQUAL:
					case '<':
					case LESSEQUAL:
					case EQUAL:
					case NOTEQUAL:
					case LOGICALAND:
					case LOGICALOR:
						n2 = numbersStack.top();
						numbersStack.pop();
						n1 = numbersStack.top();
						numbersStack.pop();
						try {
							temp2 = calculate(n1, operatorsStack.top(), n2);
						}
						catch (const char* msg) {
							error = true;
							cerr << msg << endl;
						}
						operatorsStack.pop();
						numbersStack.push(temp2);
						break;
					}
				}
				operatorsStack.push(*it);
			}
			addToNumberStack = false;
		}
		else
		{
			tempPtr = (&(*it));
			temp = tempPtr[0];
			temp2 = temp - '0'; // ASCII to regular character
			if (addToNumberStack)
			{
				temp2 = (numbersStack.top() * 10) + (temp2); // Multiple digit number
				numbersStack.pop();
				numbersStack.push(temp2);
			}
			else
			{
				numbersStack.push(temp2);
			}
			addToNumberStack = true;
		}
		/*
		if (!numbersStack.empty())
		cout << "NUM = " << numbersStack.top() << endl;
		else
		cout << "NUM empty" << endl;
		if (!operatorsStack.empty())
		cout << "OP = " << operatorsStack.top() << endl;
		else
		cout << "OP empty" << endl;
		cout << (&(*it)) << endl;
		cout << "---------------------" << endl;
		*/
	}
	return numbersStack.top();
}
void infixParser::isBalanced(string str)
{
	int open = 0, close = 0, openPlace = -1, closePlace = -1, count = 1;
	string errorMsg;
	string::iterator stringItr;
	for (stringItr = expn.begin(); stringItr < expn.end(); ++stringItr)
	{
		if (*stringItr == '(')
		{
			open++;
			if (openPlace == -1)
			{
				openPlace = count;
			}
		}
		else if (*stringItr == ')')
		{
			close++;
			if (closePlace == -1)
			{
				closePlace = count;
			}
		}
		++count;
	}
	if (open != close)
	{
		error = true;
		if (open > close)
		{
			errorMsg = "Mismatch parenthese in the expression @char " + to_string(openPlace);
		}
		else
		{
			errorMsg = "Mismatch parenthese in the expression @char " + to_string(closePlace);
		}
		throw errorMsg.c_str();
	}
}
double infixParser::calculate(double number1, char op, double number2 = -1)
{
	// Order
	// number1 op number2
	switch (op)
	{
	case '!':
		return !number1;
	case PLUS:
		return number1 + 1;
	case MINUS:
		return number1 - 1;
	case NEGATIVE:
		return -1 * number1;
	case '^':
		return pow(number1, number2);
	case '*':
		return number1 * number2;
	case '/':
		if (number2 == 0)
			throw "Zero divison error";
		return number1 / number2;
	case '%':
		return int(number1) % int(number2);
	case '+':
		return number1 + number2;
	case '-':
		return number1 - number2;
	case '>':
		return int(number1 > number2);
	case GREATEREQUAL:
		return int(number1 >= number2);
	case '<':
		return int(number1 < number2);
	case LESSEQUAL:
		return int(number1 <= number2);
	case EQUAL:
		return int(number1 == number2);
	case NOTEQUAL:
		return int(number1 != number2);
	case LOGICALAND:
		return int(number1 && number2);
	case LOGICALOR:
		return int(number1 || number2);
	default:
		return 0;
	}
}
bool infixParser::isBinaryOperator(char op)
{
	switch (op) {
	case '^':
	case '*':
	case '/':
	case '%':
	case '+':
	case '-':
	case '>':
	case '<':
	case GREATEREQUAL:
	case LESSEQUAL:
	case EQUAL:
	case NOTEQUAL:
	case LOGICALAND:
	case LOGICALOR:
		return true;
	default:
		return false;
	}
}
bool infixParser::isUnaryOperator(char op)
{
	switch (op) {
	case '!':
	case PLUS:
	case MINUS:
	case NEGATIVE:
		return true;
	default:
		return false;
	}
}
void infixParser::properNumberOfArgs(string expn)
{
	// Binary operators without two arguments
	// Check if before is number
	// Check if after is number
	string::iterator it, it_prev, it_next;
	string errorMsg;
	int count = 1;
	for (it = expn.begin(); it < expn.end(); ++it, ++count)
	{
		if (isBinaryOperator((&(*it))[0]))
		{
			it_prev = it;
			it_next = it;
			--it_prev;
			++it_next;
			if ((!isdigit(*it_prev)) || (!isdigit(*it_next)))
			{
				error = true;
				errorMsg = "Binary operator with improper arguments @ char " + to_string(count);
				throw errorMsg.c_str();
			}
		}
		else if (isUnaryOperator((&(*it))[0]))
		{
			it_next = it;
			++it_next;
			if (!isdigit(*it_next))
			{
				error = true;
				errorMsg = "Unary operator with improper arguments @ char " + to_string(count);
				throw errorMsg.c_str();
			}
		}
	}
}