/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:36:28 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/23 17:36:29 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <iostream>
#include <stdint.h>
#include "data.hpp"

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer &);
		Serializer &operator=(const Serializer &);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
    	static Data* deserialize(uintptr_t raw);
};

#endif