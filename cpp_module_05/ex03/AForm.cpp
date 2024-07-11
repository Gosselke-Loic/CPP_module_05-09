/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:38:13 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/05 10:13:24 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::~AForm( void )
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm( void ): _name("default"), _signed(false), _grade_sign(150),
	_grade_exec(150)
{
	std::cout << "AForm default constructor called: " << std::endl << *this;
}

AForm::AForm( std::string const &name, short int const &grade_sign,
	short int const &grade_exec ): _name(name), _signed(false),
	_grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (this->getGradeExec() < 1 || this->getGradeSign() < 1)
		throw (GradeTooHighException());
	if (this->getGradeExec() > 150 || this->getGradeSign() > 150)
		throw (GradeTooLowException());
	std::cout << "AForm constructor called: " << std::endl << *this;
}

AForm::AForm( AForm const &copy ): _name(copy.getName()),
	_signed(copy.getSigned()), _grade_sign(copy.getGradeSign()),
	_grade_exec(copy.getGradeExec())
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm const	&AForm::operator=( AForm const &copy )
{
	if (this != &copy)
		this->setSigned(copy._signed);
	return (*this);
}

void	AForm::setSigned( bool const &signed_copy )
{
	this->_signed = signed_copy;
}

bool const	&AForm::getSigned( void ) const
{
	return (this->_signed);
}

std::string const	&AForm::getName( void ) const
{
	return (this->_name);
}

short int const	&AForm::getGradeSign( void ) const
{
	return (this->_grade_sign);
}

short int const	&AForm::getGradeExec( void ) const
{
	return (this->_grade_exec);
}

char const  *AForm::GradeTooLowException::what( void ) const throw()
{
	return ("Grade is too low");
}

char const  *AForm::GradeTooHighException::what( void ) const throw()
{
	return ("Grade is too high");
}

char const  *AForm::NotSignedException::what( void ) const throw()
{
	return ("Form is not signed");
}

void	AForm::beSigned( Bureaucrat const &bureaucrat )
{
	if (this->getSigned())
		return;
	if (bureaucrat.getGrade() <= this->getGradeSign())
		this->setSigned(true);
	else
		throw (GradeTooLowException());
}

void	AForm::execute( Bureaucrat const &executor ) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->getSigned())
		throw (NotSignedException());
	else
		this->beExecuted();
}

std::ostream	&operator<<(std::ostream &str, AForm const &form)
{
	str << "Name: " << form.getName() << std::endl;
	str << "Signed: " << (form.getSigned() ? "true" : "false") << std::endl;
	str << "Grade to exec: " << form.getGradeExec() << std::endl;
	str << "Grade to sign: " << form.getGradeSign() << std::endl;
	return (str);
}