#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(char *av)
{
    this->_arg = av;
    this->parseRPN();
    this->workNow(this->_arg);
}

void RPN::parseRPN()
{
    if (this->_arg.empty())
        throw "Error"; 
    for (size_t i = 0; i < this->_arg.size(); i++)
    {
        if (!isdigit(this->_arg[i]) && this->_arg[i] != '*'
            && this->_arg[i] != '-' &&  this->_arg[i] != '+'
            && this->_arg[i] != '/' && this->_arg[i] != ' ')
                throw "Error";
    }
}

void    RPN::workNow(std::string arg)
{
    for (size_t i = 0; i < arg.size(); i++)
    {
        std::cout<<arg[i];
    }
    
}

RPN::~RPN()
{
}