/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 10:43:42 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/05 04:52:57 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "AForm.hpp"  // ✅ Add this include

class AForm; // optional forward declaration

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		/* ---------- Orthodox Canonical Form ---------- */
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &rhs);
		~Bureaucrat();

		/* ---------- Getters ---------- */
		const std::string &getName() const;
		int getGrade() const;

		/* ---------- Grade modification ---------- */
		void incrementGrade();
		void decrementGrade();

		/* ---------- Interaction methods ---------- */
		void signForm(AForm &form);
		void executeForm(AForm const &form) const;   // 👈 New method

		/* ---------- Exception classes ---------- */
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
