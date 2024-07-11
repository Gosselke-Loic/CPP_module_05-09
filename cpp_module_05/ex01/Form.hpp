/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:50:19 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/04 15:29:56 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
        bool				_signed;
		const short int		_grade_sign;
		const short int		_grade_exec;

		void	setSigned( bool const &signed_copy );
	public:
		Form( void );
		virtual ~Form( void );
		Form( Form const &copy );
		Form const	&operator=( Form const &copy );
		Form( std::string const &name, short int const &grade_sign,
			short int const &grade_exec );
		
		std::string const	&getName( void ) const;
		bool const			&getSigned( void ) const;
		short int const		&getGradeSign( void ) const;
		short int const		&getGradeExec( void ) const;

		void	beSigned( Bureaucrat const &bureaucrat );

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
};

std::ostream    &operator<<(std::ostream &str, Form const &form);

#endif