#pragma once
#include <iostream>
#include <string>
#include <stack>
<<<<<<< HEAD

using namespace std;
class infixParser
{
public:
	infixParser();
	infixParser(string expn, bool error);
	void getAnswer();
	
	
=======
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
>>>>>>> origin/master

private:
	bool error;
	string expn;
	double answer;
	stack<double> numbersStack;
	stack<char> operatorsStack;
<<<<<<< HEAD
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
=======
	bool isUnaryOperator(char op);
	bool isBinaryOperator(char op);
	void properNumberOfArgs(string expn);
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
>>>>>>> origin/master
};

