/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit <hmoukit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:49:22 by hmoukit           #+#    #+#             */
/*   Updated: 2025/11/04 23:07:03 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"   // We’ll need the Bureaucrat class here

class Bureaucrat; // Forward declaration (good practice to avoid circular includes)

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;

	public:
		/* ---------- Orthodox Canonical Form ---------- */
		Form();
		Form(const std::string &name, int gradeToSign, int gradeToExec);
		Form(const Form &src);
		Form &operator=(const Form &rhs);
		~Form();

		/* ---------- Getters ---------- */
		const std::string &getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		/* ---------- Core Method ---------- */
		void beSigned(const Bureaucrat &b);

		/* ---------- Exception Classes ---------- */
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

/* ---------- Operator Overload ---------- */
std::ostream &operator<<(std::ostream &out, const Form &f);

#endif
