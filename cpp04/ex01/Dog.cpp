/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:49:40 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/08 21:53:17 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog constructor called - a loyal companion joins the pack" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called - another good boy appears" << std::endl;
    // Deep copy of the brain
    brain = new Brain(*(other.brain));
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called - becoming a different dog" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        // Delete existing brain and deep copy the other's brain
        delete brain;
        brain = new Brain(*(other.brain));
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called - the loyal friend departs with a wag" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
    return brain;
}

void Dog::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return brain->getIdea(index);
}