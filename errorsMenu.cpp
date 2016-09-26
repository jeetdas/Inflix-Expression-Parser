#include <iostream> 
using namespace std;

int main (){
	std::std::map<char, string> map;


	//errors at the beginning of a expression
	errorMap[")"] = " a closing parenthese";
	errorMap["^"] = " a carrot operator";
	errorMap["*"] = " a multipication operator";
	errorMap["/"] = " a dividson operator";
	errorMap["%"] = " a mod operator ";
	errorMap[">"] = " a comparison operator";
	errorMap["<"] = " a comparison operator";
	errorMap[">="] = " a comparison operator";
	errorMap["<="] = " a comparison operator";
	errorMap["=="] = " a comparison operator";
	errorMap["!="] = " a comparison operator";
	errorMap["&&"] = " a comparison operator";
	errorMap["||"] = " a comparison operator";


	//errors with in the expression 
	errorMap[" "] = " a space between numbers, unable to read expression for evaluation";
	errorMap[""]

	cout << "Expression cannot start with " << errorMap[] << " @ char: 0"

}