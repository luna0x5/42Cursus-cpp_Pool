/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:53:52 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/08 20:55:31 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Peculiar Creature") {
    std::cout << "WrongAnimal default constructor called - strange being emerges" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "WrongAnimal copy constructor called - duplicating an odd creature" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal assignment operator called - becoming something else" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called - odd being disappears" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "* Unidentifiable wrong animal noise *" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}
