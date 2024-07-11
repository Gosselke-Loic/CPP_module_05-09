/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:50:54 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/04 15:59:40 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		short int _grade;
		const std::string _name;
		void	setGrade( short int const &number );
	public:
		Bureaucrat( void );
		~Bureaucrat( void );
		Bureaucrat( Bureaucrat const &copy );
		Bureaucrat const	&operator=( Bureaucrat const &copy );
		Bureaucrat( std::string const &name, short int const &grade );

		std::string const &getName( void ) const;
		short int const &getGrade( void ) const;

		void	gradeUp( void );
		void	gradeDown( void );

		void	signForm( AForm &form ) const;
		void	executeForm( AForm const &form );
		
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

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat);

#endif