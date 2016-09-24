#include <iostream>
#include <cmath>
#include <stack>
using namesspace std; 

int evaluateOp(stack <int> numberStack, stack <char> operatorStack)
{
	int leftValue, rightValue;
	char theOperator = operatorStack.top();

	int result;
	switch (theOperator)
	{
	case '+'://adds the two number and returns the value
		leftValue = numberStack.top();
		numberStack.pop();
		rightValue = numberStack.top();
		numberStack.pop();
		operatorStack.pop();
		result = leftValue + rightValue;
		return result;
	case '-'://subtracts the two number and returns the value
		leftValue = numberStack.top();
		numberStack.pop();
		rightValue = numberStack.top();
		numberStack.pop();
		operatorStack.pop();
		result = leftValue - rightValue;
		return result;
	case '/'://divides the two number and returns the value
		leftValue = numberStack.top();
		numberStack.pop();
		rightValue = numberStack.top();
		numberStack.pop();
		operatorStack.pop();
		result = leftValue / rightValue;
		return result;
	case '*'://multiplies the two number and returns the value
		leftValue = numberStack.top();
		numberStack.pop();
		rightValue = numberStack.top();
		numberStack.pop();
		operatorStack.pop();
		result = leftValue * rightValue;
		return result;
	case'^'://exponent
		leftValue = numberStack.top();
		numberStack.pop();
		rightValue = numberStack.top();
		numberStack.pop();
		operatorStack.pop();
		result = pow(leftValue, rightValue);
		return result;
	case'%'://mod operator
		leftValue = numberStack.top();
		numberStack.pop();
		rightValue = numberStack.top();
		numberStack.pop();
		operatorStack.pop();
		result = leftValue % rightValue;
		return result;
	case'!'://logical not
		leftValue = numberStack.top();
		numberStack.pop();
		rightValue = numberStack.top();
		numberStack.pop();
		operatorStack.pop();
		result = 0; //false
		return result;
	case'A'://increments the left value by one ++
		leftValue = numberStack.top();
		numberStack.pop();
		operatorStack.pop();
		leftValue++;
		return leftValue;
	case'B'://decrements the left value by one --
		leftValue = numberStack.top();
		numberStack.pop();
		operatorStack.pop();
		leftValue--;
		return leftValue;
	case'C'://checks to see if two values are equal ==
		leftValue = numberStack.top();
		numberStack.pop();
		rightValue = numberStack.top();
		numberStack.pop();
		operatorStack.pop();
		if (leftValue == rightValue)//if they're equal return 1 for true
		{
			result = 1;//true
			return result;
		}
		else//else return 0 for false
		{
			result = 0;//false
			return result;
		}
	case'D'://checks to see if left value is not equal to right value !=
		leftValue = numberStack.top();
		numberStack.pop();
		rightValue = numberStack.top();
		numberStack.pop();
		operatorStack.pop();
		if (leftValue != rightValue)//returns true(1) if they are not equal
		{
			result = 1;//true
			return result;
		}
		else//if they are equal returns false(0)
		{
			result = 0;//false
			return result;
		}
	case'E'://logical and operator &&
		leftValue = numberStack.top();
		numberStack.pop();
		rightValue = numberStack.top();
		numberStack.pop();
		operatorStack.pop();
		if (leftValue == rightValue)//if they're equal return 1 for true
		{
			result = 1;//true
			return result;
		}
		else//else return 0 for false
		{
			result = 0;//false
			return result;
		}
	case'F'://logical or operator ||
		leftValue = numberStack.top();
		numberStack.pop();
		rightValue = numberStack.top();
		numberStack.pop();
		operatorStack.pop();
		result = 1;//true
		return result;
	case'G'://greater than or equal
		leftValue = numberStack.top();
		numberStack.pop();
		rightValue = numberStack.top();
		numberStack.pop();
		operatorStack.pop();
		if (leftValue >= rightValue)
		{
			result = 1;//true
			return result;
		}
		else
		{
			result = 0;//false
			return result;
		}
	case'H'://less than or equal
		leftValue = numberStack.top();
		numberStack.pop();
		rightValue = numberStack.top();
		numberStack.pop();
		operatorStack.pop();
		if (leftValue <= rightValue)

		{
			result = 1;//true
			return result;
		}
		else
		{
			result = 0;//false
			return result;
		}
	case'I'://negative
		leftValue = numberStack.top();
		numberStack.pop();
		operatorStack.pop();
		result = leftValue * -1;
		return result;

	default:
		break;
	}
}

int main()
{

	/* code */
	return 0;
}


//changes each token 
istringstream tokens();
char nextChar;
stack<int> numberStack;
stack<char> operatorStack;


while (tokens >> nextChar){
	if (isdigit(nextChar)){
		tokens.push()			//add to integer stack 
		int number;
		tokens >> number; //converts the characters to ints 
		numberStack.push(number);
	}
	else if (isOperator(nextChar)){
		int weight = precedenceOfOperator(nextChar);
		int stackWeight = precedenceOfOperator(operatorStack.top())
		if(weight >= stackWeight)
		{
			operatorStack.push(nextChar);
		}
		else
		{
			
		}
	} //errors 
	
	}
} 




// Errors 
/*try 
{
	if (/*missing parenthese)
	{
		throw 0;
	}
	else if (/* starts with < )
	{
		throw 1;
	}
	else if (/* two binary operation)
	{
		throw 2;
	}
	else if (/* two operands in a row)
	{
		throw 3;
	}
	else if (/* unary operand can't be followed)
	{
		throw 4;
	}
	else (/*division by 0)
	{
		throw 5;
	}

}

catch(int x)
{
	cout << "Expression can't start with a closing parenthesis @ char: 0" << endl;
}
catch(int x)
{
	cout << "Expression can't start with a binary operator @ char: 0" << endl;
}
catch(int x)
{
	cout << "Two binary operators in a row @ row char 3" << endl;
}
catch(int x)
{
	cout << "Two operands in a row @ char 5" << endl;
}
catch(int x)
{
	cout << "A unary operand can't be followed by a binary operator @ char 6" << endl;
}
catch(int x)
{
	cout << "division by zero @ char 2" << endl;
}
}*/