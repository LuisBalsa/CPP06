#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cmath>

static bool isChar(const std::string& s) {
    return s.length() == 3 && s[0] == '\'' && s[2] == '\'';
}

static bool isInt(const std::string& s) {
    char* end;
    errno = 0;
    long val = std::strtol(s.c_str(), &end, 10);
    return *end == '\0' && errno != ERANGE && val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max();
}

static bool isFloat(const std::string& s) {
    if (s == "nanf" || s == "+inff" || s == "-inff") return true;
    if (s.length() > 1 && s[s.length()-1] == 'f') {
        char* end;
        errno = 0;
        std::strtof(s.c_str(), &end);
        return *(end) == 'f' && *(end+1) == '\0' && errno != ERANGE;
    }
    return false;
}

static bool isDouble(const std::string& s) {
    if (s == "nan" || s == "+inf" || s == "-inf") return true;
    char* end;
    errno = 0;
    std::strtod(s.c_str(), &end);
    return *end == '\0' && errno != ERANGE;
}

void ScalarConverter::convert(const std::string& literal) {
    // Char
    if (isChar(literal)) {
        std::cout << "is char\n";
        char c = literal[1];
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(c) << "f\n";
        std::cout << "double: " << static_cast<double>(c) << "\n";
        return;
    }
    // Int
    if (isInt(literal)) {
        std::cout << "is int\n";
        int i = std::atoi(literal.c_str());
        if (i >= 32 && i <= 126)
            std::cout << "char: '" << static_cast<char>(i) << "'\n";
        else if (i >= 0 && i < 32)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: impossible\n";
        std::cout << "int: " << i << "\n";
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(i) << "f\n";
        std::cout << "double: " << static_cast<double>(i) << "\n";
        return;
    }
    // Float
    if (isFloat(literal)) {
        std::cout << "is float\n";
        float f;
        if (literal == "nanf") f = std::numeric_limits<float>::quiet_NaN();
        else if (literal == "+inff") f = std::numeric_limits<float>::infinity();
        else if (literal == "-inff") f = -std::numeric_limits<float>::infinity();
        else f = std::strtof(literal.c_str(), NULL);
        if (std::isnan(f) || std::isinf(f))
            std::cout << "char: impossible\n";
        else if (f >= 32 && f <= 126)
            std::cout << "char: '" << static_cast<char>(f) << "'\n";
        else if (f >= 0 && f < 32)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: impossible\n";
        if (std::isnan(f) || std::isinf(f))
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << static_cast<int>(f) << "\n";
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << static_cast<double>(f) << "\n";
        return;
    }
    // Double
    if (isDouble(literal)) {
        std::cout << "is double\n";
        double d;
        if (literal == "nan") d = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf") d = std::numeric_limits<double>::infinity();
        else if (literal == "-inf") d = -std::numeric_limits<double>::infinity();
        else d = std::strtod(literal.c_str(), NULL);
        if (std::isnan(d) || std::isinf(d))
            std::cout << "char: impossible\n";
        else if (d >= 32 && d <= 126)
            std::cout << "char: '" << static_cast<char>(d) << "'\n";
        else if (d >= 0 && d < 32)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: impossible\n";
        if (std::isnan(d) || std::isinf(d))
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << static_cast<int>(d) << "\n";
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(d) << "f\n";
        std::cout << "double: " << d << "\n";
        return;
    }
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}
