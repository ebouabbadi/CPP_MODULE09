#include <iostream>
#include <string>
#include <vector>

class RPN
{
private:
    int _rpn;
    std::string _arg;
public:
    RPN();
    RPN(char *av);
    void    parseRPN();
    ~RPN();
};