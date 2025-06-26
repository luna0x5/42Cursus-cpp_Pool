/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:44:59 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/08 21:53:55 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat constructor called - a feline grace enters the scene" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called - another cat materializes" << std::endl;
    // Deep copy of the brain
    brain = new Brain(*(other.brain));
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called - transforming into another feline" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        // Delete existing brain and deep copy the other's brain
        delete brain;
        brain = new Brain(*(other.brain));
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called - the cat leaves with a purr" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow! Purr..." << std::endl;
}

Brain* Cat::getBrain() const {
    return brain;
}

void Cat::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return brain->getIdea(index);
}
