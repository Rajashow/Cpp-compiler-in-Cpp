
#include "Token.hpp"
#include <queue>
#include <string>
#include <cstring>
#include <assert.h>
// TODO state all assumptions
// TODO finalize behaviour
// TODO test for nested strings/ quotes """"""
#ifndef __CPP_LEXER_H_
#define __CPP_LEXER_H_

class Lexer
{
public:
    Lexer(const char *str)
    {
        /* need to add eof check and a stream */
        stream = str;
        while ((*stream) != '\0')
        {
            if (is_id(*stream))
            {
                if (is_keyword())
                {
                    tokList.push(get_keyword());
                }
                else
                {

                    tokList.push(get_id());
                }
            }
            else if (is_digit(*stream))
            {
                tokList.push(get_number());
            }
            else if (is_op(*stream))
            {
                tokList.push(get_op());
            }
            else if (is_char())
            {
                tokList.push(get_char());
            }
            else if (is_str())
            {
                tokList.push(get_str());
            }
            else if (is_space(*stream))
            {
                stream++;
            }
            else
            {
                std::cout << "|~|" << *stream << "|~|";
                stream++;
            }
        }
    }
    /* removes the top token */
    void consume()
    {
        tokList.pop();
    }
    /* peek the top token */
    Token peek()
    {

        return tokList.front();
    }
    /* returns if the tokens are empty */
    bool empty()
    {
        return tokList.empty();
    }

private:
    void parse() {}

    bool is_keyword()
    {
        return get_keyword_size() != 0;
    }
    /* is a given char a digit */
    bool is_digit(char c)
    {
        return ('0' <= c) && (c <= '9');
    }
    /* is a given char in the set of starter id */
    bool is_id(char c)
    {
        return (
            (('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z')) || (c == '_'));
    }
    /* if a given char a space  */
    bool is_space(char c)
    {
        switch (c)
        {
        case ' ':
        case '\n':
        case '\r':
        case '\t':
        case '\b':
        case '\v':
        case '\f':
            return true;
        default:
            return false;
        }
    }
    /* if a given char a op */
    bool is_op(char c)
    {
        switch (c)
        {
        case '!':
        case '%':
        case '^':
        case '&':
        case '*':
        case '(':
        case ')':
        case '-':
        case '+':
        case '=':
        case '{':
        case '}':
        case '|':
        case '~':
        case '[':
        case ']':
        case ';':
        case ':':
        case '<':
        case '>':
        case '?':
        case ',':
        case '.':
        case '/':
        case '#':
            return true;
        default:
            return false;
        }
    }

    /* is this a single quote */
    bool is_char()
    {
        return *stream == '\'';
    }
    /* is this a double quote */
    bool is_str()
    {
        return *stream == '"' || *stream == '\"';
    }
    /* get the char for the single quoutes */
    Token get_char()
    {
        int size;
        const char *start = stream;
        if (*(start + 1) == '\\' && (*start + 3) == '\'')
        {
            size = 2;
        }
        else
        {
            size = 1;
        }

        // assert(size < 5 && size > 2);
        Token tk = Token(Token::Toktype::Char, std::string(stream + 1, size));
        stream += size + 2;
        return tk;
    }
    /* get the string  for the double quoutes */

    Token get_str()
    {
        const char *start = stream;
        while (*(start + 1) != '\"' || *(start + 1) != '"')
        {
            start++;
        }

        int size = (start - stream);
        Token tk = Token(Token::Toktype::String, std::string(stream + 1, size));
        stream += size + 2;
        return tk;
    }
    /*  get a number*/
    Token get_number()
    {
        const char *start = stream;
        int size;
        Token tk;
        while (is_digit(*start))
        {
            start++;
        }

        if (*start == '.')
        {
            start++;

            while (is_digit(*start))
            {
                start++;
            }
            size = start - stream;
            tk = Token(Token::Toktype::Float, std::string(stream, size));
        }
        else
        {
            tk = Token(Token::Toktype::Number, std::string(stream, size));
        }

        size = start - stream;

        stream += size;

        return tk;
    }
    /* get the size of the keyword*/
    int get_keyword_size()
    {
        for (auto str : keywords)
        {
            if (!strncmp(str, stream, strlen(str)))
            {
                char next_char = *(str + strlen(str));
                if (!is_id(next_char) && !is_digit(next_char))
                {
                    return strlen(str);
                }
            }
        }
        return 0;
    }

    int get_id_size()
    {
        const char *start = stream;

        while (is_digit(*start) || is_id(*start))
        {
            start++;
        }
        return start - stream;
    }
    Token get_keyword()
    {
        int size = get_keyword_size();
        Token tk = Token(Token::Toktype::Keyword, std::string(stream, size));
        stream += size;
        return tk;
    }

    /* convert the stream into an id *no safety* */
    Token get_id()
    {

        int size = get_id_size();
        Token tk = Token(Token::Toktype::Identifer, std::string(stream, size));
        stream += size;
        return tk;
    }
    /* convert the stream into an operator *no safety* */
    Token get_op()
    {
        Token::Toktype tok;
        switch (*stream)
        {
        case '(':
            tok = Token::Toktype::LeftParen;
            break;
        case ')':
            tok = Token::Toktype::RightParen;
            break;
        case '{':
            tok = Token::Toktype::LeftCurly;
            break;
        case '}':
            tok = Token::Toktype::RightCurly;
            break;
        case '[':
            tok = Token::Toktype::RightSquare;
            break;
        case ']':
            tok = Token::Toktype::LeftSquare;
            break;
        case '*':
            tok = Token::Toktype::Star;
            break;
        case '/':
            tok = Token::Toktype::Div;
            break;
        case '-':
            tok = Token::Toktype::Minus;
            break;
        case '+':
            tok = Token::Toktype::Plus;
            break;
        case '.':
            tok = Token::Toktype::Dot;
            break;
        case '%':
            tok = Token::Toktype::Mod;
            break;
        case '&':
            tok = Token::Toktype::Amp;
            break;
        case '!':
            tok = Token::Toktype::Not;
            break;
        case '|':
            tok = Token::Toktype::Line;
            break;
        case '?':
            tok = Token::Toktype::Question;
            break;
        case ':':
            tok = Token::Toktype::Colon;
            break;
        case ';':
            tok = Token::Toktype::Colon;
            break;
        case '^':
            tok = Token::Toktype::Caret;
            break;
        case '=':
            tok = Token::Toktype::Equals;
            break;
        case '#':
            tok = Token::Toktype::Hash;
            break;
        case '~':
            tok = Token::Toktype::Squiggly;
            break;
        case '<':
            tok = Token::Toktype::LessThan;
            break;
        case '>':
            tok = Token::Toktype::GreaterThan;
            break;
        case ',':
            tok = Token::Toktype::Comma;
            break;
        default:
            tok = Token::Toktype::NO_VAL;
        }
        stream++;
        return tok;
    }

    const char *stream;
    std::queue<Token> tokList;
};
#endif