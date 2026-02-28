#ifndef DFA_H
#define DFA_H
#include <string>

static std::string to_lower(std::string& str);
std::string transition(std::string& first, std::string& last, std::string& test);
static bool validate(std::string& str);

#endif