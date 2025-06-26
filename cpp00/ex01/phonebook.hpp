/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:56:15 by hmoukit           #+#    #+#             */
/*   Updated: 2025/04/09 21:47:03 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

class PhoneBook {
	private:
		Contact contacts[8];
		int Index;
		int count;
	public:
		PhoneBook();
		void addContact(const Contact &contact);
		void displayContactList() const;
		void displayContact(int index) const;
		int getCount() const;
};

bool hasUnprintable(const std::string& str);

#endif