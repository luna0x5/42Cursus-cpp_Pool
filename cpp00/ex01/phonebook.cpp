/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:13:25 by hmoukit           #+#    #+#             */
/*   Updated: 2025/04/09 21:47:03 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
    Index = 0;
    count = 0;
}

void PhoneBook::addContact(const Contact &contact)
{
    if (count < 8)
	{
        contacts[count] = contact;
        count++;
    }
	else
	{
        contacts[Index] = contact;
        Index = (Index + 1) % 8;
    }
}

int PhoneBook::getCount() const
{
    return count;
}

void PhoneBook::displayContactList() const
{
    std::cout << "|" << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    for (int i = 0; i < count; ++i)
	{
        std::cout << "|" << std::setw(10) << i << "|";
        std::string firstName = contacts[i].getFirstName();
        if (firstName.length() > 10)
            std::cout << std::setw(10) << firstName.substr(0, 9) + "." << "|";
        else
            std::cout << std::setw(10) << firstName << "|";
        std::string lastName = contacts[i].getLastName();
        if (lastName.length() > 10)
            std::cout << std::setw(10) << lastName.substr(0, 9) + "." << "|";
        else
            std::cout << std::setw(10) << lastName << "|";
        std::string nickname = contacts[i].getNickname();
        if (nickname.length() > 10)
            std::cout << std::setw(10) << nickname.substr(0, 9) + "." << "|";
        else
            std::cout << std::setw(10) << nickname << "|";
        std::cout << std::endl;
    }
}

void PhoneBook::displayContact(int index) const
{
    if (index < 0 || index >= count)
	{
        std::cout << "Error: Invalid index." << std::endl;
        return;
    }
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}
