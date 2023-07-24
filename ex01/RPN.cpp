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
            this->_Token.push_back(token);
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
    for (size_t i = 0; i < this->_Token.size(); i++)
    {
        if (this->_Token[i].size() > 1)
            throw "Error.";
        if (checkToken(this->_Token[i][0]) == false)
            throw "Error.";
        this->_Tok.push_back(this->_Token[i][0]);
    }
    if (isdigit(this->_Tok[0]) && isdigit(this->_Tok[1]) && operation(this->_Tok[2]))
    {
        if (this->_Tok[2] == '+')
            this->_Rpn.push_back((this->_Tok[0] - 48) + this->_Tok[1] - 48));
        else if (this->_Tok[2] == '-')
            this->_Rpn.push_back((this->_Tok[0] - 48) - this->_Tok[1] - 48));
        else if (this->_Tok[2] == '*')
            this->_Rpn.push_back((this->_Tok[0] - 48) * this->_Tok[1] - 48));
        else if (this->_Tok[2] == '/')
            this->_Rpn.push_back((this->_Tok[0] - 48) / this->_Tok[1] - 48));
    }
    else if (isdigit(this->_Tok[0]) && isdigit(this->_Tok[1]) && isdigit(this->_Tok[2]) && operation(this->_Tok[3]))
    {
        ;
    }
    else
    {
        std::cout << this->_Tok[0] << this->_Tok[1] << this->_Tok[2] << this->_Tok[3] << std::endl;
        throw "Error.1";
    }

    for (int i = 0; i < this->_Tok.size(); i++)
    {
        std::cout << "|" << this->_Tok[i] << "|" << std::endl;
    }
}

RPN::~RPN()
{
}