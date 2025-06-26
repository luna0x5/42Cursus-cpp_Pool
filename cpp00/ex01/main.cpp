/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:27:31 by hmoukit           #+#    #+#             */
/*   Updated: 2025/04/10 16:43:36 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

bool hasUnprintable(const std::string& str)
{
	int i = 0;
    while (str[i])
	{
        if (str[i] < 32 || str[i] > 126)
            return (true);
		i++;
    }
    return (false);
}

std::string getInput(const std::string &prompt)
{
    std::string input;

    while (true)
	{
		std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof())
		{
			std::cout << "EOF detected. Exiting..." << std::endl;
            exit(0);
        }
        if (!input.empty())
			return (input);
        std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
}

Contact addNewContact()
{
    Contact newContact;
	Contact emptyContact;
   
    std::cout << "===== ADDING NEW CONTACT =====" << std::endl;
    newContact.setFirstName(getInput("Enter First Name: "));
	if (hasUnprintable(newContact.getFirstName()))
		return (std::cout << "invalid input..." << std::endl, emptyContact);
	newContact.setLastName(getInput("Enter Last Name: "));
	if (hasUnprintable(newContact.getLastName()))
		return (std::cout << "invalid input..." << std::endl, emptyContact);
	newContact.setNickname(getInput("Enter Nickname: "));
	if (hasUnprintable(newContact.getNickname()))
		return (std::cout << "invalid input..." << std::endl, emptyContact);
	newContact.setPhoneNumber(getInput("Enter Phone Number: "));
	if (hasUnprintable(newContact.getPhoneNumber()))
		return (std::cout << "invalid input..." << std::endl, emptyContact);
	newContact.setDarkestSecret(getInput("Enter Darkest Secret: "));
	if (hasUnprintable(newContact.getDarkestSecret()))
		return (std::cout << "invalid input..." << std::endl, emptyContact);
    return (newContact);
}

void searchContact(const PhoneBook &phoneBook)
{
    if (phoneBook.getCount() == 0)
	{
        std::cout << "Phonebook is empty." << std::endl;
        return ;
    }
    phoneBook.displayContactList();
    std::string indexStr;
    int index;
    std::cout << "Enter index of contact to display: ";
    std::getline(std::cin, indexStr);
    index = std::atoi(indexStr.c_str());
    if (index == 0 && indexStr != "0")
	{
        std::cout << "Error: Invalid index format." << std::endl;
        return ;
    }
    phoneBook.displayContact(index);
}

void displayWelcomeMessage()
{
    std::cout << "===============================" << std::endl;
    std::cout << "  AWESOME 80s PHONEBOOK v1.0  " << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Available commands:" << std::endl;
    std::cout << "  ADD: Add a new contact" << std::endl;
    std::cout << "  SEARCH: Search for a contact" << std::endl;
    std::cout << "  EXIT: Quit the program" << std::endl;
    std::cout << "===============================" << std::endl;
}

int main()
{
    PhoneBook phoneBook;
    std::string command;
    
    displayWelcomeMessage();
    while (1)
	{
        std::cout << "> ";
        std::getline(std::cin, command);
        if (std::cin.eof())
		{
            std::cout << "EOF detected. Exiting..." << std::endl;
            break;
        }
		if (command == "ADD")
		{
			Contact newContact = addNewContact();
			if (!newContact.isEmpty())
			{
				phoneBook.addContact(newContact);
				std::cout << "Contact added successfully!" << std::endl;
			}
			else
				std::cout << "Contact was not added." << std::endl;
		}
		else if (command == "SEARCH")
            searchContact(phoneBook);
        else if (command == "EXIT")
		{
            std::cout << "Exiting program. All contacts lost forever!" << std::endl;
            break ;
        } 
		else
            std::cout << "Invalid command. Please use ADD, SEARCH or EXIT." << std::endl;
    }
    return (0);
}
