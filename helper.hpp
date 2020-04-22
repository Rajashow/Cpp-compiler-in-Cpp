#include <iostream>
#include <string>
#ifndef __HELPER_H_
#define __HELPER_H_
#define MAC_ERRORLOG(msg, name) errorLog(msg, #name, (name))

void errorLog(std::string msg, std::string name, std::string value)
{
    std::cout << " |E> " << msg << " || " << name << ": " << value << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Token &tok)
{
    os << " <" << to_string(tok.type) << ":" << tok.value << "> ";
    return os;
}
#endif