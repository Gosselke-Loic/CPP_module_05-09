/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:38:19 by lgosselk          #+#    #+#             */
/*   Updated: 2024/06/19 15:13:54 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_H
# define SHRUBERRYCREATIONFORM_H

#include "fstream"
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string _target;
		void	setTarget( std::string const &target );
	public:
		ShrubberyCreationForm( void );
		~ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string const &target );
		ShrubberyCreationForm( ShrubberyCreationForm const &copy );
		ShrubberyCreationForm const	&operator=( ShrubberyCreationForm const &copy );

		std::string const	&getTarget( void ) const;

		void	beExecuted( void ) const;
};

#endif