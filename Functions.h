#pragma once
#include <iostream>
#include <string>

using namespace std;
class infixParser
{
public:
	infixParser();
	
	

private:
	string removeSpaces(string str);
	int precedenceOfOperator(char op);
	string reduceExpression(string str);
	int calculate(int number1, char op, int number2 = -1);
	double processedAnswer(string expn);
	void isBalcanced(string str);
};

