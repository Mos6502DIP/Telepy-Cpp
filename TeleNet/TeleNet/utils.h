#ifndef UTILS_H
#define UTILS_H

#include <string>

void clearScreen();
std::string getPassword();
void setConsoleColor(int fg, int bg);
std::string colour(const std::string& text, const std::string& color, const std::string& background = "");

#endif
