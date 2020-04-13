#include "Token.hpp"
#include <queue>
#include <string>
#include <assert.h>
class Lexer
{
public:
    Lexer(const char *str)
    {
        stream = str;
        while ((*stream) != '\0')
        {
            if (is_id(*stream))
            {
                tokList.push(get_id());
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
    void consume()
    {

        tokList.pop();
    }
    Token peek()
    {

        return tokList.front();
    }
    bool empty()
    {
        return tokList.empty();
    }

private:
    void parse() {}
    bool is_digit(char c)
    {
        return ('0' <= c) && (c <= '9');
    }
    bool is_id(char c)
    {
        return (
            (('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z')) || (c == '_'));
    }
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
    bool is_char()
    {
        return *stream == '\'';
    }
    bool is_str()
    {
        return *stream == '"' || *stream == '\"';
    }
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
        Token tk = Token(Token::Kind::Char, std::string(stream + 1, size));
        stream += size + 2;
        return tk;
    }
    Token get_str()
    {
        const char *start = stream;
        while (*(start + 1) != '\"' || *(start + 1) != '"')
        {
            start++;
        }

        int size = (start - stream);
        Token tk = Token(Token::Kind::String, std::string(stream + 1, size));
        stream += size + 2;
        return tk;
    }
    Token get_number()
    {
        const char *start = stream;

        while (is_digit(*start))
        {
            start++;
        }
        int size = start - stream;

        Token tk = Token(Token::Kind::Number, std::string(stream, size));
        stream += size;

        return tk;
    }
    Token get_id()
    {
        const char *start = stream;

        while (is_digit(*start) || is_id(*start))
        {
            start++;
        }
        int size = start - stream;
        Token tk = Token(Token::Kind::Identifer, std::string(stream, size));
        stream += size;
        return tk;
    }
    Token get_op()
    {
        Token::Kind tok;
        switch (*stream)
        {
        case '(':
            tok = Token::Kind::LeftParen;
            break;
        case ')':
            tok = Token::Kind::RightParen;
            break;
        case '{':
            tok = Token::Kind::LeftCurly;
            break;
        case '}':
            tok = Token::Kind::RightCurly;
            break;
        case '[':
            tok = Token::Kind::RightSquare;
            break;
        case ']':
            tok = Token::Kind::LeftSquare;
            break;
        case '*':
            tok = Token::Kind::Star;
            break;
        case '/':
            tok = Token::Kind::Div;
            break;
        case '-':
            tok = Token::Kind::Minus;
            break;
        case '+':
            tok = Token::Kind::Plus;
            break;
        case '.':
            tok = Token::Kind::Dot;
            break;
        case '%':
            tok = Token::Kind::Mod;
            break;
        case '&':
            tok = Token::Kind::Amp;
            break;
        case '!':
            tok = Token::Kind::Not;
            break;
        case '|':
            tok = Token::Kind::Line;
            break;
        case '?':
            tok = Token::Kind::Question;
            break;
        case ':':
            tok = Token::Kind::Colon;
            break;
        case ';':
            tok = Token::Kind::Colon;
            break;
        case '^':
            tok = Token::Kind::Caret;
            break;
        case '=':
            tok = Token::Kind::Equals;
            break;
        case '#':
            tok = Token::Kind::Hash;
            break;
        case '~':
            tok = Token::Kind::Squiggly;
            break;
        case '<':
            tok = Token::Kind::LessThan;
            break;
        case '>':
            tok = Token::Kind::GreaterThan;
            break;
        default:
            tok = Token::Kind::NO_VAL;
        }
        stream++;
        return tok;
    }

    const char *stream;
    std::queue<Token> tokList;
};