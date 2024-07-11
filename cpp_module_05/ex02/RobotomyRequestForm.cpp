/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:38:28 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/05 09:32:55 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm( void )
{}

RobotomyRequestForm::RobotomyRequestForm( void ):
	AForm("RobotomyRequestForm", 72, 45 ), _target("default")
{}

RobotomyRequestForm::RobotomyRequestForm( std::string const &target ):
	AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(
	RobotomyRequestForm const &copy ): AForm(copy), _target(copy._target)
{}

RobotomyRequestForm const	&RobotomyRequestForm::operator=(
	RobotomyRequestForm const &copy )
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->setTarget(copy.getTarget());
	}
	return (*this);
}

void	RobotomyRequestForm::setTarget( std::string const &target )
{
	this->_target = target;
}

std::string const	&RobotomyRequestForm::getTarget( void ) const
{
	return(this->_target);
}

void	RobotomyRequestForm::beExecuted( void ) const
{
	if ((std::rand() % 2) == 0)
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << this->getTarget() << " robotomy failed" << std::endl;
}