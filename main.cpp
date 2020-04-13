#include "lexer.hpp"
#include "Token.hpp"
#include <iostream>
#include <string>
std::ostream &operator<<(std::ostream &os, const Token &tok)
{
    os << " <" << to_string(tok.type) << ":" << tok.value << "> ";
    return os;
}
int main()
{
    std::string ch = "";
    const char *p = ch.c_str();
    Lexer lex = Lexer(p);
    while (!lex.empty())
    {
        std::cout << lex.peek();
        lex.consume();
    }
    std::cout << "j";
    return 0;
}