#include <iostream>
#include "settings.h"
#include "utils.h"
#include "network.h"

std::string version = "1.5";
std::string type = "win-lite";

int main() {
    clearScreen();
    
    

    Settings settings;
    if (!loadSettings("config.txt", settings)) {
        setup(settings);
        saveSettings("config.txt", settings);
    }

    //std::cout << "Your weather location is set to: " << settings.location << std::endl;
    //std::cout << "Default server: " << (settings.defaultServer.empty() ? "None" : settings.defaultServer) << std::endl;

    std::cout << R"(
                  ,,                                          
MMP""MM""YMM    `7MM              `7MN.   `7MF'         mm    
P'   MM   `7      MM                MMN.    M           MM    
     MM  .gP"Ya   MM  .gP"Ya        M YMb   M  .gP"Ya mmMMmm  
     MM ,M'   Yb  MM ,M'   Yb       M  `MN. M ,M'   Yb  MM    
     MM 8M""""""  MM 8M""""""       M   `MM.M 8M""""""  MM    
     MM YM.    ,  MM YM.    ,       M     YMM YM.    ,  MM    
   .JMML.`Mbmmd'.JMML.`Mbmmd'     .JML.    YM  `Mbmmd'  `Mbmo


)";
   
    std::cout << colour("TeleNet", "green") << " by " << colour("Peter Cakebread", "blue") << "  2025 " << version << " " << type << " " << std::endl;
    std::string ip;
    std::cout << "Enter server IP :>";
    std::getline(std::cin, ip);
    if (ip.empty()) ip = settings.defaultServer;

    if (ip.empty()) {
        std::cout << "No server provided. Exiting." << std::endl;
        return 1;
    }

    connectToServer(ip.c_str(), 1998);

    return 0;
}
