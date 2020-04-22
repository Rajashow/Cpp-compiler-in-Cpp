#include <string>
#include <vector>
#include "Token.hpp"
#ifndef __CPP_Parser_H_
#define __CPP_Parser_H_
class ParserToks
{
public:
    ParserToks()
    {
        a = 10;
    }
    int a;
};
class Op
{
};
class Exp
{
public:
    Exp(Exp left, Op op, Exp right)
    {
    }
};
class Functions
{
public:
    Functions(std::string name, std::string return_type, std::vector<std::string> arg_types, std::vector<Token> args, std::vector<ParserToks> ops)
    {
        this->name = name;
        this->return_type = return_type;
        this->arg_types = arg_types;
        this->args = args;
        this->ops = ops;
    }

    std::string name;
    std::string return_type;
    std::vector<std::string> arg_types;
    std::vector<Token> args;
    std::vector<ParserToks> ops;
};

#endif