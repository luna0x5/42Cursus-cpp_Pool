/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 04:40:52 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/05 04:43:53 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream> // for file creation

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
		/* ---------- Orthodox Canonical Form ---------- */
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
		~ShrubberyCreationForm();

		/* ---------- Override ---------- */
		void action() const; // unique behavior

		/* ---------- Getter ---------- */
		const std::string &getTarget() const;
};

#endif