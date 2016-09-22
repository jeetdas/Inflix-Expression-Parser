#include <iostream>
#include <stack>
using namesspace std; 

int evaluateOp(char operator,int numberStack, char operatorStack)
{
	int leftValue = numberStack.pop();
	int rightValue = numberStack.pop();
	int result;
	switch(operator)
	{
		case '+':
		result = leftValue + rightValue;
		return result;
		break;
		case '-':
		result = leftValue - rightValue;
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