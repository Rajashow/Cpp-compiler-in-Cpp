#include <string>
#include <iostream>
#include "lexer.hpp"
#include "Token.hpp"
// #ifdef _DEBUG
#include "helper.hpp"
// #endif

int main()
{
    std::string msg = "abc";
    Token::Toktype tk = Token::Toktype::Identifer;

    const char *p = msg.c_str();
    Lexer lex = Lexer(p);
    while (!lex.empty())
    {
        std::cout << lex.peek();
        lex.consume();
    }
    std::cout << std::endl
              << "END";
    return 0;
}