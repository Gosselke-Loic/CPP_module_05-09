/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:42:07 by lgosselk          #+#    #+#             */
/*   Updated: 2024/06/19 15:08:36 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern( void );
		~Intern( void );
		Intern( Intern const &copy );
		Intern const &operator=( Intern const &copy );

		AForm	*makeForm( std::string const &formName,
			std::string const &target );

		AForm	*makeRobotomyForm( std::string const &target );
		AForm	*makeShrubberyForm( std::string const &target );
		AForm	*makePresidentialForm( std::string const &target );

		class FormNameException: public std::exception
		{
			public:
				char const *what(void) const throw();
		};
};

#endif