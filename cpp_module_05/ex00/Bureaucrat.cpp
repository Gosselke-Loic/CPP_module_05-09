/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:50:37 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/04 15:52:53 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat( void ): _grade(150), _name("default")
{
	std::cout << "Bureaucrat default constructor called with name "
		<< *this << std::endl;
}

Bureaucrat::Bureaucrat( std::string const &name, short int const &grade ):
	_name(name)
{
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	else
		this->setGrade(grade);
	std::cout << "Bureaucrat constructor called with name "
		<< *this << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const &copy )
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = copy;
}

Bureaucrat const	&Bureaucrat::operator=( Bureaucrat const &copy )
{
	if (this != &copy)
		this->setGrade(copy.getGrade());
	return (*this);
}

std::string const	&Bureaucrat::getName( void ) const
{
	return (this->_name);
}

short int const	&Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade( short int const &number )
{
	this->_grade = number;
}

void	Bureaucrat::gradeUp( void )
{
	try
	{
		if ((this->getGrade() - 1) < 1)
			throw (GradeTooHighException());
		else
			this->setGrade(this->getGrade() - 1);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::gradeDown( void )
{
	try
	{
		if ((this->getGrade() + 1) > 150)
			throw (GradeTooLowException());
		else
			this->setGrade(this->getGrade() + 1);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

char const  *Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Grade is too low");
}

char const  *Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Grade is too high");
}

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat)
{
	return (str << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade());
}