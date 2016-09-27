#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;
class infixParser
{
public:
	infixParser();
	infixParser(string str);
	string getExpn();
	void setExpn(string str);
	double getAnswer();

private:
	bool error;
	string expn;
	double answer;
	stack<double> numbersStack;
	stack<char> operatorsStack;
	string removeSpaces(string str);
	int precedenceOfOperator(char op);
	string reduceExpression(string str);
	double calculate(double number1, char op, double number2 = -1);
	double processedAnswer(string expn);
	void isBalanced(string str);
	static const char PLUS = 'A'; // ++
	static const char MINUS = 'B'; // --
	static const char EQUAL = 'C'; // ==
	static const char NOTEQUAL = 'D'; // !=
	static const char LOGICALAND = 'E'; // &&
	static const char LOGICALOR = 'F'; // ||
	static const char GREATEREQUAL = 'G'; // >=
	static const char LESSEQUAL = 'H'; // <=
	static const char NEGATIVE = 'I'; // -2
};

