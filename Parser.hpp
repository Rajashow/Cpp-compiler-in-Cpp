#include <string>
#include <iostream>
#include <queue>
#include "lexer.hpp"
// #ifdef _DEBUG
#include "helper.hpp"
// #endif
#ifndef __CPP_Parser_H_
#define __CPP_Parser_H_
extern const char *const keywords[];
class Parser
{
public:
    Parser(Lexer lexer)
    {
        this->lexer = lexer;
        while (!lexer.empty())
        {
            parseStmt();
        }
    }

private:
    void parseFunc()
    {
        Token tk = lexer.peek();
        switch (tk.getType())
        {
        case Token::Toktype::Keyword:
            if (!tk.value.compare("int"))
            {
            }
            else if (!tk.value.compare("void"))
            {
            }
            else if (!tk.value.compare("bool"))
            {
            }
            else if (!tk.value.compare("float"))
            {
            }
            else
            {
                MAC_ERRORLOG("unsupported function statement keyword", tk.value)
                return
            }

            break;
        case Token::Toktype::Identifer:
        // TODO implement diff types
        default:
            MAC_ERRORLOG("unsupported function statement", to_string(tk.getType()))
            MAC_ERRORLOG("|____>", tk.value)
        }
    }
    void parseStmt()
    {
        switch (lexer.peek().getType())
        {
            // case In
        }
    }
    void parseExp() {}
    Lexer lexer;
    std::queue<Token> parseTokQ;
};
#endif
