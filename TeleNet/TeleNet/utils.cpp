#include "utils.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <unordered_map>
#include <string>

void clearScreen() {
    system("cls");
}

std::string getPassword() {
    std::string pwd;
    char ch;
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!pwd.empty()) {
                pwd.pop_back();
                std::cout << "\b \b";
            }
        }
        else {
            pwd.push_back(ch);
            std::cout << '*';
        }
    }
    std::cout << "\n";
    return pwd;
}

void setConsoleColor(int fg, int bg) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bg << 4) | fg);
}

std::string colour(const std::string& text, const std::string& color, const std::string& background) {
    // Define color mappings
    static const std::unordered_map<std::string, std::string> colors = {
        {"black", "\033[30m"},
        {"red", "\033[31m"},
        {"green", "\033[32m"},
        {"yellow", "\033[33m"},
        {"blue", "\033[34m"},
        {"magenta", "\033[35m"},
        {"cyan", "\033[36m"},
        {"white", "\033[37m"},
        {"light_black", "\033[90m"},
        {"light_red", "\033[91m"},
        {"light_green", "\033[92m"},
        {"light_yellow", "\033[93m"},
        {"light_blue", "\033[94m"},
        {"light_magenta", "\033[95m"},
        {"light_cyan", "\033[96m"},
        {"light_white", "\033[97m"},
        {"reset", "\033[0m"}
    };

    // Define background color mappings
    static const std::unordered_map<std::string, std::string> backgrounds = {
        {"black", "\033[40m"},
        {"red", "\033[41m"},
        {"green", "\033[42m"},
        {"yellow", "\033[43m"},
        {"blue", "\033[44m"},
        {"magenta", "\033[45m"},
        {"cyan", "\033[46m"},
        {"white", "\033[47m"},
        {"light_black", "\033[100m"},
        {"light_red", "\033[101m"},
        {"light_green", "\033[102m"},
        {"light_yellow", "\033[103m"},
        {"light_blue", "\033[104m"},
        {"light_magenta", "\033[105m"},
        {"light_cyan", "\033[106m"},
        {"light_white", "\033[107m"},
        {"reset", "\033[0m"}
    };

    // Get foreground color code; fallback to reset if not found.
    std::string color_code;
    auto it = colors.find(color);
    if (it != colors.end()) {
        color_code = it->second;
    }
    else {
        color_code = colors.at("reset");
    }

    // Get background code if provided; otherwise, it remains empty.
    std::string background_code;
    if (!background.empty()) {
        auto bg_it = backgrounds.find(background);
        if (bg_it != backgrounds.end()) {
            background_code = bg_it->second;
        }
    }

    // Combine background code, foreground color code, text, and reset at the end.
    return background_code + color_code + text + colors.at("reset");
}
