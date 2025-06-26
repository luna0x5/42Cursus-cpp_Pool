/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:59:42 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/09 08:56:22 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void testBasicAnimalFunctionality() {
    std::cout << "\n===== TESTING BASIC ANIMAL FUNCTIONALITY =====\n" << std::endl;
    
    Animal animal;
    std::cout << "Animal type: " << animal.getType() << std::endl;
    std::cout << "Animal sound: ";
    animal.makeSound();
    
    Animal animal2 = animal;
    std::cout << "Copied animal type: " << animal2.getType() << std::endl;
    
    Animal animal3;
    animal3 = animal;
    std::cout << "Assigned animal type: " << animal3.getType() << std::endl;
}

void testDogFunctionality() {
    std::cout << "\n===== TESTING DOG FUNCTIONALITY =====\n" << std::endl;
    
    Dog dog;
    std::cout << "Dog type: " << dog.getType() << std::endl;
    std::cout << "Dog sound: ";
    dog.makeSound();
    
    Dog dog2 = dog;
    std::cout << "Copied dog type: " << dog2.getType() << std::endl;
    
    Dog dog3;
    dog3 = dog;
    std::cout << "Assigned dog type: " << dog3.getType() << std::endl;
}

void testCatFunctionality() {
    std::cout << "\n===== TESTING CAT FUNCTIONALITY =====\n" << std::endl;
    
    Cat cat;
    std::cout << "Cat type: " << cat.getType() << std::endl;
    std::cout << "Cat sound: ";
    cat.makeSound();
    
    Cat cat2 = cat;
    std::cout << "Copied cat type: " << cat2.getType() << std::endl;
    
    Cat cat3;
    cat3 = cat;
    std::cout << "Assigned cat type: " << cat3.getType() << std::endl;
}

void testPolymorphism() {
    std::cout << "\n===== TESTING POLYMORPHISM =====\n" << std::endl;
    
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "Animal type: " << animal->getType() << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;
    
    std::cout << "\nAnimal sound: ";
    animal->makeSound();
    std::cout << "Dog sound (through Animal pointer): ";
    dog->makeSound();
    std::cout << "Cat sound (through Animal pointer): ";
    cat->makeSound();
    
    delete animal;
    delete dog;
    delete cat;
}

void testWrongAnimalFunctionality() {
    std::cout << "\n===== TESTING WRONG ANIMAL FUNCTIONALITY =====\n" << std::endl;
    
    WrongAnimal wrongAnimal;
    std::cout << "WrongAnimal type: " << wrongAnimal.getType() << std::endl;
    std::cout << "WrongAnimal sound: ";
    wrongAnimal.makeSound();
    
    WrongCat wrongCat;
    std::cout << "WrongCat type: " << wrongCat.getType() << std::endl;
    std::cout << "WrongCat sound: ";
    wrongCat.makeSound();
}

void testFailedPolymorphism() {
    std::cout << "\n===== TESTING FAILED POLYMORPHISM =====\n" << std::endl;
    
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "WrongAnimal type: " << wrongAnimal->getType() << std::endl;
    std::cout << "WrongCat type (through WrongAnimal pointer): " << wrongCat->getType() << std::endl;
    
    std::cout << "\nWrongAnimal sound: ";
    wrongAnimal->makeSound();
    std::cout << "WrongCat sound (through WrongAnimal pointer - should NOT meow!): ";
    wrongCat->makeSound();
    
    delete wrongAnimal;
    delete wrongCat;
}

void testComparisonBetweenCorrectAndWrong() {
    std::cout << "\n===== COMPARING CORRECT VS WRONG IMPLEMENTATION =====\n" << std::endl;
    
    std::cout << "Correct implementation (with virtual functions):" << std::endl;
    const Animal* cat = new Cat();
    std::cout << "Cat through Animal pointer sound: ";
    cat->makeSound();
    delete cat;
    
    std::cout << "\nIncorrect implementation (without virtual functions):" << std::endl;
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << "WrongCat through WrongAnimal pointer sound: ";
    wrongCat->makeSound();
    delete wrongCat;
}

int main()
{
	std::cout << "======= ANIMAL CLASS HIERARCHY TESTS =======\n" << std::endl;
	testBasicAnimalFunctionality();
	testDogFunctionality();
	testCatFunctionality();
	testPolymorphism();
	testWrongAnimalFunctionality();
	testFailedPolymorphism();
	testComparisonBetweenCorrectAndWrong();
	std::cout << "\n======= ALL TESTS COMPLETED =======\n" << std::endl;

}
