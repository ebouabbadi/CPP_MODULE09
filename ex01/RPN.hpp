#include <iostream>
#include <string>
#include <vector>

class RPN
{
private:
    std::string _arg;
    std::vector<int>    _Rpn;
    std::vector<std::string>    _Token;
public:
    RPN();
    RPN(char *av);
    void    parseRPN();
    void    workNow(std::string argn);
    void split_arg();

    ~RPN();
};