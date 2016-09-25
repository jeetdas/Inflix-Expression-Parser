#include <iostream> 
using namespace std;

int main (){
	std::std::map<char, string> map;

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


	cout << "Expression cannot start with " << errorMap[] << " @ char: 0"

}