#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;
class inflixParser
{
public:
	inflixParser();
	inflixParser(string str);
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
	int calculate(int number1, char op, int number2 = -1);
	double processedAnswer(string expn);
	void isBalcanced(string str);
	void properNumberOfArgs(string expn);
	bool isUnaryOperator(char op);
	bool isBinaryOperator(char op);
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

