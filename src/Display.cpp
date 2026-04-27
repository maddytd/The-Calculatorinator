#include "Display.h"

std::ostream& bold_on(std::ostream& os) // creates macro for turning on and off bold
{
    return os << "\e[1m";
}

std::ostream& bold_off(std::ostream& os)
{
    return os << "\e[0m";
}

std::ostream& underline_on(std::ostream& os)
{
    return os << "\033[4m";
}

std::ostream& underline_off(std::ostream& os)
{
    return os << "\033[24m";
}