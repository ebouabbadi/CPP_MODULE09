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
        if (!isdigit(this->_arg[i]) && this->_arg[i] != '*' && this->_arg[i] != '-' && this->_arg[i] != '+' && this->_arg[i] != '/' && this->_arg[i] != ' ')
            throw "Error";
    }
}

void RPN::workNow(std::string arg)
{
    for (size_t i = 0; i < arg.size(); i++)
    {
        std::string nb;
        while (arg[i] && isdigit(arg[i]))
        {
            nb.push_back(arg[i]);
            i++;
        }
        this->_Rpn.push_back(std::atoi(nb.c_str()));
        std::cout << nb << std::endl;
        std::cout << "................." << std::endl;
    }
}

RPN::~RPN()
{
}