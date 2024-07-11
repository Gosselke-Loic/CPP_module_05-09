/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:38:08 by lgosselk          #+#    #+#             */
/*   Updated: 2024/06/19 15:28:32 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
        bool				_signed;
		const short int		_grade_sign;
		const short int		_grade_exec;

		void	setSigned( bool const &signed_copy );
	public:
		AForm( void );
		virtual ~AForm( void );
		AForm( AForm const &copy );
		AForm const	&operator=( AForm const &copy );
		AForm( std::string const &name, short int const &grade_sign,
			short int const &grade_exec );
		
		std::string const	&getName( void ) const;
		bool const			&getSigned( void ) const;
		short int const		&getGradeSign( void ) const;
		short int const		&getGradeExec( void ) const;
		
		virtual void	beExecuted( void ) const = 0;
		void			beSigned( Bureaucrat const &bureaucrat );
		void			execute( Bureaucrat const &executor ) const;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};

		class NotSignedException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
};

std::ostream    &operator<<(std::ostream &str, AForm const &form);

#endif