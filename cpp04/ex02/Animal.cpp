/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:34:18 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/08 20:43:06 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Unknown Creature") {
    std::cout << "Animal default constructor called - a mysterious creature appears" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copy constructor called - cloning a " << type << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assignment operator called - transforming into a " << other.type << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called - " << type << " vanishes into thin air" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "* Generic animal noise *" << std::endl;
}

std::string Animal::getType() const {
    return type;
}