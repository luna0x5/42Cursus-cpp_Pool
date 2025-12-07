/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 03:27:29 by hmoukit           #+#    #+#             */
/*   Updated: 2025/12/07 16:23:51 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>

RPN::RPN()
{}

RPN::RPN(const RPN& other) : _stack(other._stack)
{}


RPN &RPN::operator=(const RPN& other)
{
    if (this == &other)
        _stack = other._stack;
    return *this;
}

RPN::~RPN()
{}

bool RPN::isOperator(char c) const
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::isNumber(const std::string& token) const
{
    if (token.length() != 1)
        return false;
    return (token[0] >= '0' && token[0] <= '9');
}

int RPN::performOperation(int a, int b, char op) const
{
    switch (op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: division by zero");
            return a / b;
        default:
            throw std::runtime_error("Error: invalid operator");
    }
}

int RPN::evaluate(const std::string& expression)
{
    std::istringstream iss(expression); // treat the string line an in stream
    std::string token;
    
    while (iss >> token)
    {
        if (isNumber(token))
            _stack.push(token[0] - '0');
        else if (token.length() == 1 && isOperator(token[0]))
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error: insufficient operands");
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();
            int result = performOperation(a, b, token[0]);
            _stack.push(result);
        }
        else
            throw std::runtime_error("Error: invalid token");
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid expression");
    return _stack.top();
}