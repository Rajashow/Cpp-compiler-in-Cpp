#include <string>
#include <iostream>
#ifndef __CPP_Token_H_
#define __CPP_Token_H_
// TODO if out if this is the right way ??
const constexpr char *const keywords[] = {
    "asm",
    "else",
    "new",
    "this",
    "auto",
    "enum",
    "operator",
    "throw",
    "bool",
    "explicit",
    "private",
    "true",
    "break",
    "export",
    "protected",
    "try",
    "case",
    "extern",
    "public",
    "typedef",
    "catch",
    "false",
    "register",
    "typeid",
    "char",
    "float",
    "reinterpret_cast",
    "typename",
    "class",
    "for",
    "return",
    "union",
    "const",
    "friend",
    "short",
    "unsigned",
    "const_cast",
    "goto",
    "signed",
    "using",
    "continue",
    "if",
    "sizeof",
    "virtual",
    "default",
    "inline",
    "static",
    "void",
    "delete",
    "int",
    "static_cast",
    "volatile",
    "do",
    "long",
    "struct",
    "wchar_t",
    "double",
    "mutable",
    "switch",
    "while",
    "dynamic_cast",
    "namespace",
    "template",

};
class Token
{
public:
    enum class Toktype
    {
        Number,
        Float,
        Identifer,
        Keyword,
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
    Toktype type;
    std::string value;
    Token(Toktype kind, std::string val)
    {
        type = kind;
        value = val;
    }
    Token()
    {
        type = Toktype::NO_VAL;
        value = "";
    }
    Token(Toktype kind)
    {
        type = kind;
        value = "";
    }
    Toktype getType()
    {
        return type;
    }
};

inline std::string to_string(Token::Toktype kind)
{
    switch (kind)
    {
    case Token::Toktype::Number:;
        return "Number";
    case Token::Toktype::Keyword:;
        return "Keyword";
    case Token::Toktype::Identifer:
        return "Identifer";
    case Token::Toktype::String:
        return "String";
    case Token::Toktype::Float:
        return "Float";
    case Token::Toktype::LeftParen:
        return "LeftParen";
    case Token::Toktype::RightParen:
        return "RightParen";
    case Token::Toktype::Char:
        return "Char";
    case Token::Toktype::LeftSquare:
        return "LeftSquare";
    case Token::Toktype::RightSquare:
        return "RightSquare";
    case Token::Toktype::LeftCurly:
        return "LeftCurly";
    case Token::Toktype::RightCurly:
        return "RightCurly";
    case Token::Toktype::LessThan:
        return "LessThan";
    case Token::Toktype::Squiggly:
        return "Squiggly";
    case Token::Toktype::GreaterThan:
        return "GreaterThan";
    case Token::Toktype::Semicolon:
        return "Semicolon";
    case Token::Toktype::Caret:
        return "Caret";
    case Token::Toktype::Not:
        return "Not";
    case Token::Toktype::Equals:
        return "Equals";
    case Token::Toktype::Question:
        return "Question";
    case Token::Toktype::SingleQuote:
        return "SingleQuote";
    case Token::Toktype::FordSlash:
        return "FordSlash";
    case Token::Toktype::BackSlash:
        return "BackSlash";
    case Token::Toktype::Comma:
        return "Comma";
    case Token::Toktype::DoubleQuote:
        return "DoubleQuote";
    case Token::Toktype::Colon:
        return "Colon";
    case Token::Toktype::Hash:
        return "Hash";
    case Token::Toktype::Plus:
        return "Plus";
    case Token::Toktype::Minus:
        return "Minus";
    case Token::Toktype::Div:
        return "Div";
    case Token::Toktype::Star:
        return "Star";
    case Token::Toktype::Mod:
        return "Mod";
    case Token::Toktype::Amp:
        return "Amp";
    case Token::Toktype::Line:
        return "Line";
    case Token::Toktype::Dot:
        return "Dot";
    case Token::Toktype::End:
        return "End";
    case Token::Toktype::NO_VAL:
        return "NO_VAL";
    default:
        return "OUT OF BOUNDS TOKEN???";
    }
}
#endif