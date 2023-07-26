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
    int j = 0;
    for (int i = 0; i < arg.size(); i++)
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
    // if (!isdigit(this->_T[0][0]))
    //     throw "Error.";
    for (int i = 1; i < this->_T.size(); i++)
    {
        if (isdigit(this->_T[i][0]))
        {
            this->_Rpn.push_back(std::stoi(_T[i]));
            std::cout << "->>>" << std::stoi(_T[i]) << std::endl;
        }
        else
        {
            if (_T[i][0] == '+')
            {
                this->_Rpn.push_back(_Rpn[0] + _Rpn[1]);
                std::cout << "->>>" << (_Rpn[0] + _Rpn[1]) << std::endl;
                // else if (_T[i][0] == '-')

                // else if (_T[i][0] == '*')

                // else if (_T[i][0] == '/')
            }
        }
        for (int i = 0; i < _Rpn.size(); i++)
        {
            std::cout << "|" << this->_Rpn[i] << "|" << std::endl;
        }
    }
}
    RPN::~RPN()
    {
    }