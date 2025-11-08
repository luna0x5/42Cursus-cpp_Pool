/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 10:43:40 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/08 12:38:17 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "----- Valid Bureaucrats -----" << std::endl;
    try
    {
        Bureaucrat a("Alice", 2);
        Bureaucrat b("Bob", 149);

        std::cout << a << std::endl;
        std::cout << b << std::endl;

        std::cout << "\n----- Increment / Decrement Tests -----" << std::endl;

        a.incrementGrade(); // ok -> becomes 1
        b.decrementGrade(); // ok -> becomes 150

        std::cout << a << std::endl;
        std::cout << b << std::endl;

        std::cout << "\nTrying to increment Alice again (should throw)" << std::endl;
        a.incrementGrade(); // grade 0 -> throws
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n----- Invalid Bureaucrats (should throw) -----" << std::endl;

    try
    {
        Bureaucrat c("Charlie", 0); // too high
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat d("Diana", 151); // too low
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n----- Decrement too low (should throw) -----" << std::endl;
    try
    {
        Bureaucrat e("Edward", 150);
        std::cout << e << std::endl;
        e.decrementGrade(); // goes to 151 -> throws
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n----- Copy and Assignment Tests -----" << std::endl;
    Bureaucrat original("Frank", 42);
    Bureaucrat copy(original);
    Bureaucrat assigned("Temp", 120);
    assigned = original;

    std::cout << "Original: " << original << std::endl;
    std::cout << "Copy:     " << copy << std::endl;
    std::cout << "Assigned: " << assigned << std::endl;

    return 0;
}

