#pragma once
#include <iostream>
#include <string>
#include <stack>

using namespace std;
class infixParser
{
public:
	infixParser();
	infixParser(string expn, bool error);
	void getAnswer();
	
	

private:
	bool error;
	string expn;
	double answer;
	stack<double> numbersStack;
	stack<char> operatorsStack;
	string removeSpaces(string str);
	int precedenceOfOperator(char op);
	string reduceExpression(string str);
	int calculate(int number1, char op, int number2 = -1);
	double processedAnswer(string expn);
	void isBalcanced(string str);
	const char PLUS = 'A'; // ++
	const char MINUS = 'B'; // --
	const char EQUAL = 'C'; // ==
	const char NOTEQUAL = 'D'; // !=
	const char LOGICALAND = 'E'; // &&
	const char LOGICALOR = 'F'; // ||
	const char GREATEREQUAL = 'G'; // >=
	const char LESSEQUAL = 'H'; // <=
	const char NEGATIVE = 'I'; // -2
};

