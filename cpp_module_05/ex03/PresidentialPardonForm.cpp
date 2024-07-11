/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:37:39 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/05 09:53:02 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm( void )
{}

PresidentialPardonForm::PresidentialPardonForm( void ):
	AForm("PresidentialPardonForm", 25, 5 ), _target("default")
{}

PresidentialPardonForm::PresidentialPardonForm( std::string const &target ):
	AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(
	PresidentialPardonForm const &copy ): AForm(copy), _target(copy._target)
{}

PresidentialPardonForm const	&PresidentialPardonForm::operator=(
	PresidentialPardonForm const &copy )
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->setTarget(copy.getTarget());
	}
	return (*this);
}

void	PresidentialPardonForm::setTarget( std::string const &target )
{
	this->_target = target;
}

std::string const	&PresidentialPardonForm::getTarget( void ) const
{
	return(this->_target);
}

void	PresidentialPardonForm::beExecuted( void ) const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox"
		<< std::endl;
}