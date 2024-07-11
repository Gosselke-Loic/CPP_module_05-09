/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:50:12 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/04 15:36:19 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::~Form( void )
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form( void ): _name("default"), _signed(false), _grade_sign(150),
	_grade_exec(150)
{
	std::cout << "Form default constructor called: " << std::endl << *this;
}

Form::Form( std::string const &name, short int const &grade_sign,
	short int const &grade_exec ): _name(name), _signed(false),
	_grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (this->getGradeExec() < 1 || this->getGradeSign() < 1)
		throw (GradeTooHighException());
	if (this->getGradeExec() > 150 || this->getGradeSign() > 150)
		throw (GradeTooLowException());
	std::cout << "Form constructor called: " << std::endl << *this;
}

Form::Form( Form const &copy ): _name(copy.getName()),
	_signed(copy.getSigned()), _grade_sign(copy.getGradeSign()),
	_grade_exec(copy.getGradeExec())
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form const	&Form::operator=( Form const &copy )
{
	if (this != &copy)
		this->setSigned(copy._signed);
	return (*this);
}

void	Form::setSigned( bool const &signed_copy )
{
	this->_signed = signed_copy;
}

bool const	&Form::getSigned( void ) const
{
	return (this->_signed);
}

std::string const	&Form::getName( void ) const
{
	return (this->_name);
}

short int const	&Form::getGradeSign( void ) const
{
	return (this->_grade_sign);
}

short int const	&Form::getGradeExec( void ) const
{
	return (this->_grade_exec);
}

char const  *Form::GradeTooLowException::what( void ) const throw()
{
	return ("Form: grade is too low");
}

char const  *Form::GradeTooHighException::what( void ) const throw()
{
	return ("Form: grade is too high");
}

void	Form::beSigned( Bureaucrat const &bureaucrat )
{
	if (this->getSigned())
		return;
	if (bureaucrat.getGrade() <= this->getGradeSign())
		this->setSigned(true);
	else
		throw(GradeTooLowException());
}

std::ostream	&operator<<(std::ostream &str, Form const &form)
{
	str << "Name: " << form.getName() << std::endl;
	str << "Signed: " << (form.getSigned() ? "true" : "false") << std::endl;
	str << "Grade to exec: " << form.getGradeExec() << std::endl;
	str << "Grade to sign: " << form.getGradeSign() << std::endl;
	return (str);
}