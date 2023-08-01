#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(char *av)
{
    this->_arg = av;
    this->parseRPN();
}

std::string eraseSpaces(std::string input)
{
    size_t first = input.find_first_not_of(' ');
    if (first == std::string::npos)
        return "";
    size_t last = input.find_last_not_of(' ');
    return input.substr(first, last - first + 1);
}
void RPN::split_arg(std::string arg)
{
    arg = eraseSpaces(arg);
    if (arg.empty())
        throw "Error.";
    for (size_t i = 0; i < arg.size(); i++)
    {
        std::string token;
        while (arg[i] && arg[i] != ' ')
        {
            token.push_back(arg[i]);
            i++;
        }
        if (!token.empty())
            this->_T.push_back(token);
    }
}

bool checkToken(char c)
{
    if (!isdigit(c) && c != '/' && c != '+' && c != '-' && c != '*')
        return (false);
    return (true);
}

bool operation(char c)
{
    if (c != '+' && c != '-' && c != '*' && c != '/')
        return (false);
    return (true);
}

void RPN::calculateNumber(char _c)
{
    if (isdigit(_c))
    {
        int n = _c - 48;
        this->_Rpn.push_back(n);
    }
    else if (_c == '+' && this->_Rpn.size() >= 2)
    {
        int b = this->_Rpn[this->_Rpn.size() - 1];
        this->_Rpn.pop_back();
        int a = this->_Rpn[this->_Rpn.size() - 1];
        this->_Rpn.pop_back();
        this->_Rpn.push_back(a + b);
    }
    else if (_c == '-' && this->_Rpn.size() >= 2)
    {
        std::cout<<",,,,\n";
        int b = this->_Rpn[this->_Rpn.size() - 1];
        this->_Rpn.pop_back();
        int a = this->_Rpn[this->_Rpn.size() - 1];
        this->_Rpn.pop_back();
        this->_Rpn.push_back(a - b);
    }
    else if (_c == '*' && this->_Rpn.size() >= 2)
    {
        int b = this->_Rpn[this->_Rpn.size() - 1];
        this->_Rpn.pop_back();
        int a = this->_Rpn[this->_Rpn.size() - 1];
        this->_Rpn.pop_back();
        this->_Rpn.push_back(a * b);
    }
    else if (_c == '/' && this->_Rpn.size() >= 2)
    {
        int b = this->_Rpn[this->_Rpn.size() - 1];
        this->_Rpn.pop_back();
        int a = this->_Rpn[this->_Rpn.size() - 1];
        this->_Rpn.pop_back();
        this->_Rpn.push_back(a / b);
    }
    else
        throw "Error.";
}

void RPN::parseRPN()
{
    this->split_arg(this->_arg);
    for (size_t i = 0; i < this->_T.size(); i++)
    {
        if (this->_T[i].size() > 1)
            throw "Error.";
        if (checkToken(this->_T[i][0]) == false)
            throw "Error.";
    }
    for (size_t i = 0; i < this->_T.size(); i++)
        this->calculateNumber(this->_T[i][0]);
    if (this->_Rpn.size() == 1)
	{
		int result = this->_Rpn[this->_Rpn.size() - 1];
		this->_Rpn.pop_back();
		std::cout << result << std::endl;
	}
	else
		throw "Error.";
}
RPN::~RPN()
{
}