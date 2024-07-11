/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:38:24 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/05 09:33:03 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{}

ShrubberyCreationForm::ShrubberyCreationForm( void ):
	AForm("ShrubberyCreationForm", 145, 137), _target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const &target ):
	AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(
	ShrubberyCreationForm const &copy ): AForm(copy), _target(copy._target)
{}

ShrubberyCreationForm const	&ShrubberyCreationForm::operator=(
	ShrubberyCreationForm const &copy )
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->setTarget(copy.getTarget());
	}
	return (*this);
}

void	ShrubberyCreationForm::setTarget( std::string const &target )
{
	this->_target = target;
}

std::string const	&ShrubberyCreationForm::getTarget( void ) const
{
	return(this->_target);
}

void	ShrubberyCreationForm::beExecuted( void ) const
{
    std::ofstream   outfile;

    outfile.open((this->getTarget() + "_shrubbery").c_str());
    if (outfile.fail())
    {
        std::cout << "Outfile could not be opened" << std::endl;
        return ;
    }
    outfile << "   /\\" << std::endl;
    outfile << "  /  \\" << std::endl;
    outfile << "  /  \\" << std::endl;
    outfile << " /    \\" << std::endl;
    outfile << " /    \\" << std::endl;
    outfile << "/      \\" << std::endl;
    outfile << "  | |" << std::endl;
    outfile << "  | |" << std::endl;
    outfile.close();
}