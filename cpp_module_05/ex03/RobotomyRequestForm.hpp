/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:38:40 by lgosselk          #+#    #+#             */
/*   Updated: 2024/06/19 11:14:03 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string _target;
		void	setTarget( std::string const &target );
	public:
		RobotomyRequestForm( void );
		~RobotomyRequestForm( void );
		RobotomyRequestForm( std::string const &target );
		RobotomyRequestForm( RobotomyRequestForm const &copy );
		RobotomyRequestForm const	&operator=( RobotomyRequestForm const &copy );

		std::string const	&getTarget( void ) const;

		void	beExecuted( void ) const;
};

#endif