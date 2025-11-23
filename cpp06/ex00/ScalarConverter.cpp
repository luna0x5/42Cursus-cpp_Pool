/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:35:51 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/23 17:40:27 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{}
ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void)copy;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    (void)copy;
    return *this;
}
ScalarConverter::~ScalarConverter()
{}

static bool isCharLiteral(const std::string &s)
{
    if (s[0] == '\'' && s.length() == 3)
        return (1);
    return (s.length() == 1 && !std::isdigit(s[0]));
}

static bool isIntLiteral(const std::string &s)
{
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (; i < s.length(); ++i)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return (s.length() > 0);
}

static bool isFloatLiteral(const std::string &s)
{
    // if (s == "nanf" || s == "+inff" || s == "-inff")
    //     return true;
    bool dot = false;
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (; i < s.length() - 1; ++i)
    {
        if (s[i] == '.')
        {
            if (dot) return false;
            dot = true;
        }
        else if (!std::isdigit(s[i]))
            return false;
    }
    return (s[s.length() - 1] == 'f');
}

static bool isDoubleLiteral(const std::string &s)
{
    // if (s == "nan" || s == "+inf" || s == "-inf")
    //     return true;
    bool dot = false;
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (; i < s.length(); ++i)
    {
        if (s[i] == '.')
        {
            if (dot) return false;
            dot = true;
        }
        else if (!std::isdigit(s[i]))
            return false;
    }
    return dot;
}

static double strToDouble(const std::string &s)
{
    std::istringstream iss(s);
    double d;
    iss >> d;
    return d;
}

static float strToFloat(const std::string &s)
{
    std::istringstream iss(s);
    float f;
    iss >> f;
    return f;
}

static int strToInt(const std::string &s)
{
    std::istringstream iss(s);
    int i;
    iss >> i;
    return i;
}

static bool handleSpecialLiterals(const std::string &literal)
{
    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
        return true;
    }
    if (literal == "+inf" || literal == "+inff" ||
        literal == "inf" || literal == "inff")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: +inff\n";
        std::cout << "double: +inf\n";
        return true;
    }
    if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";
        return true;
    }
    return false;
}

static eLiteralType detectType(const std::string &literal)
{
    if (isCharLiteral(literal))
        return TYPE_CHAR;
    if (isIntLiteral(literal))
        return TYPE_INT;
    if (isFloatLiteral(literal))
        return TYPE_FLOAT;
    if (isDoubleLiteral(literal))
        return TYPE_DOUBLE;
    return TYPE_INVALID;
}

static double convertToDouble(const std::string &literal, eLiteralType type)
{
    if (type == TYPE_CHAR)
    {
        if (literal[0] == '\'')
            return static_cast<double>(literal[1]);
        return static_cast<double>(literal[0]);
    }
    if (type == TYPE_INT)
        return static_cast<double>(strToInt(literal));
    if (type == TYPE_FLOAT)
        return static_cast<double>(strToFloat(literal));
    if (type == TYPE_DOUBLE)
        return strToDouble(literal);
    return 0.0;
}

static void printAllConversions(double value)
{
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "char: ";
    if (std::isnan(value) || value < 0 || value > 127)
        std::cout << "impossible";
    else if (std::isprint(static_cast<int>(value)))
        std::cout << "'" << static_cast<char>(value) << "'";
    else
        std::cout << "Non displayable";
    std::cout << std::endl;
    std::cout << "int: ";
    if (std::isnan(value) || value > INT_MAX || value < INT_MIN)
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(value);
    std::cout << std::endl;
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convert(std::string const &literal)
{
    if (handleSpecialLiterals(literal))
        return ;
    eLiteralType type = detectType(literal);
    if (type == TYPE_INVALID)
    {
        std::cerr << "Error: invalid literal format\n";
        return ;
    }
    double value = convertToDouble(literal, type);
    printAllConversions(value);
}
