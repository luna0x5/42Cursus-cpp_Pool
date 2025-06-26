/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:29:45 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/08 22:41:57 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

void testInstantiation() {
    std::cout << "===== INSTANTIATION TEST =====" << std::endl;

    // Animal a; // This line should fail to compile if uncommented

    Dog dog;
    Cat cat;

    dog.makeSound();
    cat.makeSound();
}

void testPolymorphismAndDestruction() {
    std::cout << "\n===== POLYMORPHISM AND DESTRUCTION TEST =====" << std::endl;

    Animal* animals[4];
    for (int i = 0; i < 2; ++i)
        animals[i] = new Dog();
    for (int i = 2; i < 4; ++i)
        animals[i] = new Cat();

    for (int i = 0; i < 4; ++i)
        animals[i]->makeSound();  // Polymorphic call

    for (int i = 0; i < 4; ++i)
        delete animals[i];  // Virtual destructors should ensure proper cleanup
}

int main() {
    testInstantiation();
    testPolymorphismAndDestruction();

    return 0;
}
