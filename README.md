# 42 C++ Pool

A comprehensive collection of C++ exercises from the 42 curriculum, covering fundamental to intermediate object-oriented programming concepts.

## Overview

This pool contains 10 modules (cpp00 through cpp09) with progressively advanced exercises designed to teach core C++ concepts including memory management, OOP principles, polymorphism, exceptions, and advanced C++ features.

## Modules

### cpp00 - Introduction to C++
- **ex00**: `megaphone` - Simple string manipulation
- **ex01**: `phonebook` - Phonebook management system with contact storage

**Concepts**: Basic I/O, std::string, std::cout/std::cin, simple data structures

### cpp01 - Memory & Pointers
- **ex00**: `newZombie` & `randomChump` - Dynamic memory allocation
- **ex01**: `zombieHorde` - Array allocation and memory management
- **ex02**: References and memory addressing
- **ex03**: `Weapon` class - Pointer and reference usage
- **ex04**: File I/O and string operations
- **ex05**: `Harl` - Function pointers and polymorphism alternatives
- **ex06**: `Harl` - String-based method switching

**Concepts**: new/delete, pointers, references, dynamic arrays, file I/O, function pointers

### cpp02 - The Orthodox Canonical Form
- **ex00-ex02**: `Fixed` class - Fixed-point numbers with operator overloading

**Concepts**: 
- Constructors (default, copy, parameterized)
- Destructors
- Copy assignment operator
- Operator overloading (arithmetic, comparison, increment/decrement)
- const correctness

### cpp03 - Inheritance
- **ex00**: `ClapTrap` - Base class
- **ex01**: `ScavTrap` - Single inheritance from ClapTrap
- **ex02**: `FragTrap` - Multi-level inheritance hierarchy

**Concepts**: 
- Inheritance
- Method overriding
- Access modifiers (public, protected, private)
- Constructor/destructor chaining

### cpp04 - Polymorphism
- **ex00**: `Animal`, `Cat`, `Dog`, `WrongAnimal`, `WrongCat` - Virtual functions basics
- **ex01**: `Brain` class - Deep copy and polymorphism
- **ex02**: Advanced polymorphic behavior

**Concepts**:
- Virtual functions
- Abstract classes
- Polymorphic behavior
- Virtual destructors
- Deep vs. shallow copy

### cpp05 - Exception Handling & Design Patterns
- **ex00**: `Bureaucrat` - Basic exception throwing
- **ex01**: `Form` - Exception propagation
- **ex02**: `AForm`, `PresidentialPardonForm`, etc. - Abstract base classes
- **ex03**: Bureaucrat workflow system

**Concepts**:
- try/catch/throw
- Custom exceptions
- std::exception
- Abstract classes (pure virtual functions)
- Inheritance with exceptions

### cpp06-cpp09 - Advanced Topics
- **cpp06**: Type casting and RTTI
- **cpp07**: Templates and template specialization
- **cpp08**: STL containers and iterators
- **cpp09**: STL algorithms and advanced patterns

**Concepts**: Templates, RTTI (Run-Time Type Information), STL containers, iterators, algorithms

## Building & Running

### Prerequisites
- C++98 standard compliance (or specified C++ version)
- GNU Make
- g++ or clang++

### Compilation

Each exercise has its own Makefile. To build:

```bash
cd cpp0X/exXX
make
```

### Execution

After building:

```bash
./[executable_name]
```

Example:
```bash
cd cpp00/ex00
make
./megaphone "hello world"
```

### Cleaning

Remove build artifacts:

```bash
cd cpp0X/exXX
make clean      # Remove object files
make fclean    # Remove all generated files
make re        # Clean and rebuild
```

## Project Structure

```
├── cpp00/          # Introduction to C++
├── cpp01/          # Memory & Pointers
├── cpp02/          # Orthodox Canonical Form
├── cpp03/          # Inheritance
├── cpp04/          # Polymorphism
├── cpp05/          # Exception Handling
├── cpp06-cpp09/    # Advanced Topics (In Progress)
└── README.md
```

Each module (cpp0X) contains:
- **exXX/** directories with individual exercises
- **Makefile** for compilation
- **.cpp** source files
- **.hpp** header files
- **main.cpp** entry point (usually includes test cases)

## Learning Objectives

By completing this pool, you will understand:

✓ Core C++ syntax and semantics  
✓ Memory management (stack vs. heap, new/delete)  
✓ Object-oriented design principles  
✓ Inheritance hierarchies  
✓ Polymorphism and virtual functions  
✓ Exception handling  
✓ Operator overloading  
✓ The Orthodox Canonical Form (destructor, copy constructor, assignment operator)  
✓ File I/O operations  
✓ Const correctness  

## Tips & Best Practices

- **Compile with flags**: Consider adding `-Wall -Wextra -Werror` to your Makefile
- **Follow the Orthodox Canonical Form**: Implement destructor, copy constructor, and assignment operator
- **Const correctness**: Use const where appropriate for methods and parameters
- **Memory safety**: Always delete dynamically allocated memory (use destructors)
- **Avoid global variables**: Encapsulate state in classes
- **Code organization**: Separate interface (.hpp) from implementation (.cpp)

## Status

- ✅ cpp00 - Complete
- ✅ cpp01 - Complete
- ✅ cpp02 - Complete
- ✅ cpp03 - Complete
- ✅ cpp04 - Complete
- ✅ cpp05 - Complete
- ✅ cpp06 - Complete
- ✅ cpp07 - Complete
- ✅ cpp08 - Complete
- ✅ cpp09 - Complete

## Resources

- [cppreference.com](https://en.cppreference.com/) - C++ standard library reference
- [LearnCPP.com](https://www.learncpp.com/) - Comprehensive C++ tutorials
- 42 School Documentation - Internal resources

---

**Note**: This is part of the 42 School curriculum. All exercises should follow the project specifications and 42 coding norms.
