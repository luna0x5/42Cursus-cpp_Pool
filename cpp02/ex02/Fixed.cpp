/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 05:01:37 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/03 05:08:51 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    value = n << fractBits;
}

Fixed::Fixed(const float n) 
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(n * (1 << fractBits));
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->value = rhs.getRawBits();
    }
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(value) / (1 << fractBits);
}

int Fixed::toInt(void) const
{
    return value >> fractBits;
}

bool Fixed::operator>(const Fixed &rhs) const
{
    return this->value > rhs.value;
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return this->value < rhs.value;
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return this->value >= rhs.value;
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return this->value <= rhs.value;
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return this->value == rhs.value;
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return this->value != rhs.value;
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
    Fixed result;
    result.setRawBits(this->value + rhs.value);
    return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    Fixed result;
    result.setRawBits(this->value - rhs.value);
    return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    if (rhs.value == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++()
{
    // Pre-increment: ++a
    this->value += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    // Post-increment: a++
    Fixed temp(*this);
    this->value += 1;
    return temp;
}
 
Fixed &Fixed::operator--()
{
    // Pre-decrement: --a
    this->value -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    // Post-decrement: a--
    Fixed temp(*this);
    this->value -= 1;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}
