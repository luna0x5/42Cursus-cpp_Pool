/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:22:45 by hmoukit           #+#    #+#             */
/*   Updated: 2025/05/09 08:58:32 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void testAnimalArray() {
    std::cout << "\n===== TESTING ANIMAL ARRAY REQUIREMENT =====\n" << std::endl;
    
    const int arraySize = 10;
    Animal* animals[arraySize];
    
    // Fill half with Dogs and half with Cats as required
    std::cout << "Creating array with " << arraySize/2 << " dogs and " << arraySize/2 << " cats:" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        if (i < arraySize / 2) {
            animals[i] = new Dog();
            std::cout << "Created Dog at index " << i << std::endl;
        } else {
            animals[i] = new Cat();
            std::cout << "Created Cat at index " << i << std::endl;
        }
    }
    
    // Test polymorphic behavior using the array
    std::cout << "\nTesting polymorphic behavior:" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Animal[" << i << "] type: " << animals[i]->getType() << ", sound: ";
        animals[i]->makeSound();
    }
    
    // Delete all animals through base class pointers
    std::cout << "\nDeleting all animals through base pointers (should call proper destructors):" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }
}

void testDeepCopy() {
    std::cout << "\n===== TESTING DEEP COPY =====\n" << std::endl;
    
    // ========== DOG DEEP COPY TESTS ==========
    std::cout << "--- Dog Deep Copy Tests ---" << std::endl;
    
    // Create original dog with ideas
    Dog* originalDog = new Dog();
    originalDog->setIdea(0, "I love bones");
    originalDog->setIdea(1, "I want to chase cars");
    originalDog->setIdea(2, "My human is awesome");
    
    std::cout << "Original dog ideas:" << std::endl;
    std::cout << "Idea 0: " << originalDog->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << originalDog->getIdea(1) << std::endl;
    std::cout << "Idea 2: " << originalDog->getIdea(2) << std::endl;
    
    // Test copy constructor (deep copy)
    std::cout << "\nCopy constructor test:" << std::endl;
    Dog* copiedDog = new Dog(*originalDog);
    
    // Verify addresses are different
    std::cout << "Original dog brain address: " << originalDog->getBrain() << std::endl;
    std::cout << "Copied dog brain address: " << copiedDog->getBrain() << std::endl;
    
    // Verify copied ideas are the same
    std::cout << "\nVerifying copied ideas:" << std::endl;
    std::cout << "Copied dog idea 0: " << copiedDog->getIdea(0) << std::endl;
    std::cout << "Copied dog idea 1: " << copiedDog->getIdea(1) << std::endl;
    std::cout << "Copied dog idea 2: " << copiedDog->getIdea(2) << std::endl;
    
    // Modify original dog's ideas
    std::cout << "\nModifying original dog's ideas:" << std::endl;
    originalDog->setIdea(0, "MODIFIED: I'm hungry now");
    originalDog->setIdea(1, "MODIFIED: Let's go for a walk");
    
    // Verify that copied dog's ideas are unchanged (proving deep copy)
    std::cout << "\nVerifying copied dog ideas remain unchanged:" << std::endl;
    std::cout << "Original dog idea 0: " << originalDog->getIdea(0) << std::endl;
    std::cout << "Original dog idea 1: " << originalDog->getIdea(1) << std::endl;
    std::cout << "Copied dog idea 0: " << copiedDog->getIdea(0) << " (should still be the original idea)" << std::endl;
    std::cout << "Copied dog idea 1: " << copiedDog->getIdea(1) << " (should still be the original idea)" << std::endl;
    
    // Test assignment operator (deep copy)
    std::cout << "\nAssignment operator test:" << std::endl;
    Dog* assignedDog = new Dog();
    assignedDog->setIdea(0, "Some initial thought");
    *assignedDog = *originalDog;
    
    // Verify addresses are different
    std::cout << "Original dog brain address: " << originalDog->getBrain() << std::endl;
    std::cout << "Assigned dog brain address: " << assignedDog->getBrain() << std::endl;
    
    // Verify assigned ideas are the same as original
    std::cout << "\nVerifying assigned ideas:" << std::endl;
    std::cout << "Assigned dog idea 0: " << assignedDog->getIdea(0) << std::endl;
    std::cout << "Assigned dog idea 1: " << assignedDog->getIdea(1) << std::endl;
    
    // Modify original dog's ideas again
    std::cout << "\nModifying original dog's ideas again:" << std::endl;
    originalDog->setIdea(0, "MODIFIED AGAIN: Where's my ball?");
    
    // Verify that assigned dog's ideas are unchanged (proving deep copy)
    std::cout << "\nVerifying assigned dog ideas remain unchanged:" << std::endl;
    std::cout << "Original dog idea 0: " << originalDog->getIdea(0) << std::endl;
    std::cout << "Assigned dog idea 0: " << assignedDog->getIdea(0) << " (should be the previous modified idea)" << std::endl;
    
    // Clean up
    delete originalDog;
    delete copiedDog;
    delete assignedDog;
    
    // ========== CAT DEEP COPY TESTS ==========
    std::cout << "\n--- Cat Deep Copy Tests ---" << std::endl;
    
    // Create original cat with ideas
    Cat* originalCat = new Cat();
    originalCat->setIdea(0, "I am the ruler of this house");
    originalCat->setIdea(1, "I need to knock over that vase");
    originalCat->setIdea(2, "Humans exist to serve me");
    
    std::cout << "Original cat ideas:" << std::endl;
    std::cout << "Idea 0: " << originalCat->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << originalCat->getIdea(1) << std::endl;
    std::cout << "Idea 2: " << originalCat->getIdea(2) << std::endl;
    
    // Test copy constructor (deep copy)
    std::cout << "\nCopy constructor test:" << std::endl;
    Cat* copiedCat = new Cat(*originalCat);
    
    // Verify addresses are different
    std::cout << "Original cat brain address: " << originalCat->getBrain() << std::endl;
    std::cout << "Copied cat brain address: " << copiedCat->getBrain() << std::endl;
    
    // Verify copied ideas are the same
    std::cout << "\nVerifying copied ideas:" << std::endl;
    std::cout << "Copied cat idea 0: " << copiedCat->getIdea(0) << std::endl;
    std::cout << "Copied cat idea 1: " << copiedCat->getIdea(1) << std::endl;
    std::cout << "Copied cat idea 2: " << copiedCat->getIdea(2) << std::endl;
    
    // Modify original cat's ideas
    std::cout << "\nModifying original cat's ideas:" << std::endl;
    originalCat->setIdea(0, "MODIFIED: I demand food now");
    originalCat->setIdea(1, "MODIFIED: I need a nap");
    
    // Verify that copied cat's ideas are unchanged (proving deep copy)
    std::cout << "\nVerifying copied cat ideas remain unchanged:" << std::endl;
    std::cout << "Original cat idea 0: " << originalCat->getIdea(0) << std::endl;
    std::cout << "Original cat idea 1: " << originalCat->getIdea(1) << std::endl;
    std::cout << "Copied cat idea 0: " << copiedCat->getIdea(0) << " (should still be the original idea)" << std::endl;
    std::cout << "Copied cat idea 1: " << copiedCat->getIdea(1) << " (should still be the original idea)" << std::endl;
    
    // Test assignment operator (deep copy)
    std::cout << "\nAssignment operator test:" << std::endl;
    Cat* assignedCat = new Cat();
    assignedCat->setIdea(0, "Some initial cat thought");
    *assignedCat = *originalCat;
    
    // Verify addresses are different
    std::cout << "Original cat brain address: " << originalCat->getBrain() << std::endl;
    std::cout << "Assigned cat brain address: " << assignedCat->getBrain() << std::endl;
    
    // Verify assigned ideas are the same as original
    std::cout << "\nVerifying assigned ideas:" << std::endl;
    std::cout << "Assigned cat idea 0: " << assignedCat->getIdea(0) << std::endl;
    std::cout << "Assigned cat idea 1: " << assignedCat->getIdea(1) << std::endl;
    
    // Modify original cat's ideas again
    std::cout << "\nModifying original cat's ideas again:" << std::endl;
    originalCat->setIdea(0, "MODIFIED AGAIN: I must attack the curtains");
    
    // Verify that assigned cat's ideas are unchanged (proving deep copy)
    std::cout << "\nVerifying assigned cat ideas remain unchanged:" << std::endl;
    std::cout << "Original cat idea 0: " << originalCat->getIdea(0) << std::endl;
    std::cout << "Assigned cat idea 0: " << assignedCat->getIdea(0) << " (should be the previous modified idea)" << std::endl;
    
    // Clean up
    delete originalCat;
    delete copiedCat;
    delete assignedCat;
}

void testBrainFunctionality() {
    std::cout << "\n===== TESTING BRAIN CLASS =====\n" << std::endl;

    Brain brain;
    std::cout << "Setting ideas in the brain..." << std::endl;

    for (int i = 0; i < 5; ++i) {
        std::string idea = "Idea number ";
        idea += static_cast<char>('0' + i); // works for 0–9
        brain.setIdea(i, idea);
    }

    std::cout << "Reading back ideas:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Idea " << i << ": " << brain.getIdea(i) << std::endl;
    }

    std::cout << "\nTesting Brain copy constructor:" << std::endl;
    Brain brainCopy(brain);

    std::cout << "Reading copied brain ideas:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Copied idea " << i << ": " << brainCopy.getIdea(i) << std::endl;
    }

    std::cout << "\nModifying original brain ideas:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::string idea = "MODIFIED idea number ";
        idea += static_cast<char>('0' + i); // simple conversion
        brain.setIdea(i, idea);
    }

    std::cout << "Reading modified original brain ideas:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Original modified idea " << i << ": " << brain.getIdea(i) << std::endl;
    }

    std::cout << "Reading copied brain ideas (should be unchanged):" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Copied idea " << i << ": " << brainCopy.getIdea(i) << std::endl;
    }

    std::cout << "\nTesting Brain assignment operator:" << std::endl;
    Brain brainAssigned;
    brainAssigned = brain;

    std::cout << "Reading assigned brain ideas:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Assigned idea " << i << ": " << brainAssigned.getIdea(i) << std::endl;
    }
}

void testPolymorphicDestruction() {
    std::cout << "\n===== TESTING POLYMORPHIC DESTRUCTION =====\n" << std::endl;
    
    std::cout << "Creating a Dog as an Animal pointer:" << std::endl;
    Animal* animal1 = new Dog();
    
    std::cout << "\nCreating a Cat as an Animal pointer:" << std::endl;
    Animal* animal2 = new Cat();
    
    std::cout << "\nDeleting Dog through Animal pointer (should call both Dog and Animal destructors):" << std::endl;
    delete animal1;
    
    std::cout << "\nDeleting Cat through Animal pointer (should call both Cat and Animal destructors):" << std::endl;
    delete animal2;
}

void testMemoryLeakScenarios() {
    std::cout << "\n===== TESTING MEMORY LEAK SCENARIOS =====\n" << std::endl;
    
    std::cout << "Creating and assigning dogs (testing proper brain deletion):" << std::endl;
    Dog* dog1 = new Dog();
    Dog* dog2 = new Dog();
    
    // This should properly delete the existing brain in dog1 before assigning new one
    *dog1 = *dog2;
    
    std::cout << "\nCreating and deleting dogs:" << std::endl;
    delete dog1;
    delete dog2;
    
    std::cout << "\nCreating and assigning cats (testing proper brain deletion):" << std::endl;
    Cat* cat1 = new Cat();
    Cat* cat2 = new Cat();
    
    // This should properly delete the existing brain in cat1 before assigning new one
    *cat1 = *cat2;
    
    std::cout << "\nCreating and deleting cats:" << std::endl;
    delete cat1;
    delete cat2;
}

int main() {
    std::cout << "===========================================" << std::endl;
    std::cout << "      ANIMAL CLASS HIERARCHY TESTS         " << std::endl;
    std::cout << "===========================================" << std::endl;
    testBrainFunctionality();
    testDeepCopy();
    testPolymorphicDestruction();
    testMemoryLeakScenarios();
    testAnimalArray();
    std::cout << "\n===========================================" << std::endl;
    std::cout << "          ALL TESTS COMPLETED              " << std::endl;
    std::cout << "===========================================" << std::endl;
    
    std::cout << "\nNote: To check for memory leaks, compile and run with:" << std::endl;
    std::cout << "      valgrind --leak-check=full ./your_program" << std::endl;
    
    return 0;
}