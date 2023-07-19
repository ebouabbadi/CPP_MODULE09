#include <iostream>
#include <string>
#include <vector>

class RPN
{
private:
    std::string _arg;
    std::vector<int>    _Rpn;
public:
    RPN();
    RPN(char *av);
    void    parseRPN();
    void    workNow(std::string argn);
    ~RPN();
};