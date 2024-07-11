/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:38:49 by lgosselk          #+#    #+#             */
/*   Updated: 2024/06/19 15:13:58 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string _target;
		void	setTarget( std::string const &target );
	public:
		PresidentialPardonForm( void );
		~PresidentialPardonForm( void );
		PresidentialPardonForm( std::string const &target );
		PresidentialPardonForm( PresidentialPardonForm const &copy );
		PresidentialPardonForm const	&operator=( PresidentialPardonForm const &copy );

		std::string const	&getTarget( void ) const;

		void	beExecuted( void ) const;
};

#endif