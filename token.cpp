#include <iostream>
#include <cmath>
#include <stack>
using namesspace std; 

int evaluateOp(char theOperator,int numberStack, char operatorStack)
{
	int leftValue = numberStack.pop();
	int rightValue = numberStack.pop();
	int result;
	switch(theOperator)
	{
		case '+'://adds the two number and returns the value
			result = leftValue + rightValue;
			return result;
			break;
		case '-'://subtracts the two number and returns the value
			result = leftValue - rightValue;
			return result;
			break;
		case '/'://divides the two number and returns the value
			result = leftValue / rightValue;
			return result;
			break;
		case '*'://multiplies the two number and returns the value
			result = leftValue * rightValue;
			return result;
			break;
		case'^'://exponent
			result = pow(leftValue, rightValue);
			return result;
			break;
		case'%'://mod operator
			result = leftValue % rightValue;
			return result;
			break;
		case'!'://logical not
			result = 0; //false
			return result;
			break;
		case'A'://increments the left value by one ++
			leftValue++;
			return leftValue;
			break;
		case'B'://decrements the left value by one --
			leftValue--;
			return leftValue;
			break;
		case'C'://checks to see if two values are equal ==
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
			break;
		case'D'://checks to see if left value is not equal to right value !=
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
			break;
		case'E'://logical and operator &&
			break;
		case'F'://logical or operator ||
			result = 1;//true
			return result;
			break;
		case'G'://greater than or equal
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
			break;
		case'H'://less than or equal
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
			break;
		case'I'://negative
			result = leftValue * -1;
			return result;
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
	}
	else{
		throw caseErrors(" ");
	}
}