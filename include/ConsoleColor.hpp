/**
 * @file ConsoleColor.hpp
 * @brief Définition des codes couleurs ANSI (Version VIVES/BOLD).
 */

#ifndef CONSOLECOLOR_HPP
#define CONSOLECOLOR_HPP

#include <string>

namespace Color {
    
    const std::string RESET   = "\033[0m";
    const std::string RED     = "\033[1;31m"; 
    const std::string GREEN   = "\033[1;32m"; 
    const std::string YELLOW  = "\033[1;33m"; 
    const std::string BLUE    = "\033[1;34m"; 
    const std::string MAGENTA = "\033[1;35m"; 
    const std::string CYAN    = "\033[1;36m"; 
}

#endif