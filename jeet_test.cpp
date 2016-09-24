#include <algorithm>
#include <string>
#include <iostream>
#include <iterator>
#include <cctype>
#include <cstddef>

using namespace std;

const char PLUS = 'A'; // ++
const char MINUS = 'B'; // --
const char EQUAL = 'C'; // ==
const char NOTEQUAL = 'D'; // !=
const char LOGICALAND = 'E'; // &&
const char LOGICALOR = 'F'; // ||
const char GREATEREQUAL = 'G'; // >=
const char LESSEQUAL = 'H'; // <=
const char NEGATIVE = 'I'; // -2

const string OPERATORS = "+-*/()ABCDEFGHI!%><";

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

string makeItLowerCase(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

bool isoperator(char op)
{
    cout << "OP = " << op;
    size_t found = OPERATORS.find_first_of(op);
    if (found == string::npos)
    {
        cout << " FALSE" << endl;
        return false;
    }
    cout << "TRUE" << endl;
    return true;
}

int precedenceOfOperator(char op)
{
    switch (op)
    {
            case '!':
            case PLUS: // ++
            case MINUS: // --
            case NEGATIVE: // +2
                return 8;
            case '^':
                return 7;
            case '*':
            case '/':
            case '%':
                return 6;
            case '+':
            case '-':
                return 5;
            case '>':
            case GREATEREQUAL: // >=
            case '<':
            case LESSEQUAL: // <=
                return 4;
            case EQUAL: // ==
            case NOTEQUAL: // !=
                return 3;
            case LOGICALAND: // &&
                return 2;
            case LOGICALOR: // ||
                return 1;
            default:
                return 0; // Error case
    }
}

string reduceExpression(string str)
{
    string proccessedString = "";
    char temp;
    
    string::iterator it;
    for (it = str.begin(); it < str.end(); ++it)
    {
        if (isdigit(*it))
        {
            proccessedString += *it;
        }
        else
        {
            temp = *(++it);
            //cout << "T = " << temp << endl;
            --it;
            if (!(isdigit(temp)))
            {
                if (temp == *it)
                {
                    switch (temp)
                    {
                        case '+':
                            proccessedString += PLUS;
                            ++it;
                            break;
                        case '-':
                            proccessedString += MINUS;
                            ++it;
                            break;
                        case '&':
                            proccessedString += LOGICALAND;
                            ++it;
                            break;
                        case '|':
                            proccessedString += LOGICALOR;
                            ++it;
                            break;
                        case '=':
                            proccessedString += EQUAL;
                            ++it;
                            break;
                    }
                }
                else if (temp == '=')
                {
                    switch (*it)
                    {
                        case '>':
                            proccessedString += GREATEREQUAL;
                            ++it;
                            break;
                        case '<':
                            proccessedString += LESSEQUAL;
                            ++it;
                            break;
                        case '!':
                            proccessedString += NOTEQUAL;
                            ++it;
                            break;
                    }
                }
                else
                {
                    proccessedString += *it;
                }
            }
            else
            {
                proccessedString += *it;
            }
        }
    }
    
    return proccessedString;
}

int main()
{
    string expn;
    cout << "Enter inflix expression: ";
    //getline(cin, expn);
    
    //expn = "++++2-5*(3^2)";
    expn = "(4>=4) && 0";
    cout << "EXPN = " << expn << endl;
    
    expn = removeSpaces(expn);
    expn = makeItLowerCase(expn);
    
    cout << reduceExpression(expn) << endl;
    
    return 0;
}