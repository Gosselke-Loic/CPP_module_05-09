/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:41:56 by lgosselk          #+#    #+#             */
/*   Updated: 2024/06/19 15:08:08 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void )
{}

Intern::~Intern( void )
{}

Intern::Intern( Intern const &copy )
{
	*this = copy;
}

Intern const	&Intern::operator=( Intern const &copy )
{
	(void)&copy;
	return (*this);
}

AForm	*Intern::makeRobotomyForm( std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeShrubberyForm( std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makePresidentialForm( std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm( std::string const &formName,
	std::string const &target )
{
	std::string	forms[3] = {"shrubbery creation", "robotomy request",
		"presidential pardon"};
	AForm	*(Intern::*makers[3])(std::string const &) = {
		&Intern::makeShrubberyForm,
		&Intern::makeRobotomyForm,
		&Intern::makePresidentialForm
	};
	
	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (forms[i] == formName)
			{
				std::cout << "Intern creates " << forms[i] << std::endl;
				return ((this->*makers[i])(target));
			}
		}
		throw (FormNameException());
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (NULL);
}

char const	*Intern::FormNameException::what( void ) const throw()
{
	return ("Name of the form doesn't exit");
}
