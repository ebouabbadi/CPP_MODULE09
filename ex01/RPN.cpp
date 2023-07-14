#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(char *av)
{
    this->_arg = av;
    this->parseRPN();
}
void RPN::parseRPN()
{
    for (size_t i = 0; i < this->_arg.size(); i++)
    {
        if (!isdigit(this->_arg[i]) && this->_arg[i] != '*'
            && this->_arg[i] != '-' &&  this->_arg[i] != '+' 
            && this->_arg[i] != '/' && this->_arg[i] != ' ')
                throw "Error";
    }
}

RPN::~RPN()
{
}