#include <string>
#include <iostream>
#ifndef __CPP_Token_H_
#define __CPP_Token_H_

class Token
{
public:
    enum class Kind
    {
        Number,
        Identifer,
        String,
        Char,
        LeftParen,
        RightParen,
        LeftSquare,
        RightSquare,
        LeftCurly,
        RightCurly,
        LessThan,
        GreaterThan,
        Semicolon,
        Not,
        Equals,
        Question,
        SingleQuote,
        DoubleQuote,
        Colon,
        Hash,
        Plus,
        Minus,
        Div,
        Star,
        Mod,
        Amp,
        Line,
        Dot,
        End,
        Caret,
        FordSlash,
        BackSlash,
        Comma,
        Squiggly,
        NO_VAL,

    };
    Kind type;
    std::string value;
    Token(Kind kind, std::string val)
    {
        type = kind;
        value = val;
    }
    Token()
    {
        type = Kind::NO_VAL;
        value = "";
    }
    Token(Kind kind)
    {
        type = kind;
        value = "";
    }
};

inline std::string to_string(Token::Kind kind)
{
    switch (kind)
    {
    case Token::Kind::Number:;
        return "Number";
    case Token::Kind::Identifer:
        return "Identifer";
    case Token::Kind::String:
        return "String";
    case Token::Kind::LeftParen:
        return "LeftParen";
    case Token::Kind::RightParen:
        return "RightParen";
    case Token::Kind::Char:
        return "Char";
    case Token::Kind::LeftSquare:
        return "LeftSquare";
    case Token::Kind::RightSquare:
        return "RightSquare";
    case Token::Kind::LeftCurly:
        return "LeftCurly";
    case Token::Kind::RightCurly:
        return "RightCurly";
    case Token::Kind::LessThan:
        return "LessThan";
    case Token::Kind::Squiggly:
        return "Squiggly";
    case Token::Kind::GreaterThan:
        return "GreaterThan";
    case Token::Kind::Semicolon:
        return "Semicolon";
    case Token::Kind::Caret:
        return "Caret";
    case Token::Kind::Not:
        return "Not";
    case Token::Kind::Equals:
        return "Equals";
    case Token::Kind::Question:
        return "Question";
    case Token::Kind::SingleQuote:
        return "SingleQuote";
    case Token::Kind::FordSlash:
        return "FordSlash";
    case Token::Kind::BackSlash:
        return "BackSlash";
    case Token::Kind::Comma:
        return "Comma";
    case Token::Kind::DoubleQuote:
        return "DoubleQuote";
    case Token::Kind::Colon:
        return "Colon";
    case Token::Kind::Hash:
        return "Hash";
    case Token::Kind::Plus:
        return "Plus";
    case Token::Kind::Minus:
        return "Minus";
    case Token::Kind::Div:
        return "Div";
    case Token::Kind::Star:
        return "Star";
    case Token::Kind::Mod:
        return "Mod";
    case Token::Kind::Amp:
        return "Amp";
    case Token::Kind::Line:
        return "Line";
    case Token::Kind::Dot:
        return "Dot";
    case Token::Kind::End:
        return "End";
    case Token::Kind::NO_VAL:
        return "NO_VAL";
    default:
        return "OUT OF BOUNDS TOKEN???";
    }
}
#endif