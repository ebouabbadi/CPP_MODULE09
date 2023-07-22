#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(char *av)
{
    this->_arg = av;
    this->parseRPN();
    // this->workNow(this->_arg);
}
 
void RPN::split_arg()
{
    std::string token;
    size_t start = 0, end;

    while ((end = this->_arg.find(" ", start)) != std::string::npos)
    {
        token = this->_arg.substr(start, end - start);
        this->_Token.push_back(token);
        start = end + 1;
    }
    token = this->_arg.substr(start);
    this->_Token.push_back(token);
}

void RPN::parseRPN()
{
    if (this->_arg.empty())
        throw "Error";
    this->split_arg();
    std::vector<std::string>::iterator it = this->_Token.begin();
    std::vector<std::string>::iterator itEnd = this->_Token.end();
    // for (int i = 0; it != itEnd; it++)
    // {
        std::cout<<it[0]<<std::endl;
        std::cout<<it[1]<<std::endl;
        std::cout<<it[2]<<std::endl;
        std::cout<<it[3]<<std::endl;
        std::cout<<it[4]<<std::endl;
    // }
}

void RPN::workNow(std::string arg)
{
}

RPN::~RPN()
{
}