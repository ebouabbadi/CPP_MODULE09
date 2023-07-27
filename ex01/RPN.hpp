#include <iostream>
#include <string>
#include <vector>

class RPN
{
private:
    std::string _arg;
    std::vector<std::string> _T;
    std::vector<int> _Rpn;

public:
    RPN();
    RPN(char *av);
    void parseRPN();
    void split_arg(std::string arg);
    void    calculateNumber(char _c);
    ~RPN();
};