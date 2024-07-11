/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:44:29 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/02 10:11:14 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>

class RPN
{
	private:
		std::stack<double> _stack;
	public:
		RPN( void );
		~RPN( void );
		RPN( RPN const &copy );
		RPN( std::string const &arg );

		std::stack<double>	&getStack( void );
		std::stack<double> const	&getStack( void ) const;
		void	setStack( std::stack<double> const &stack );

		RPN const	&operator=( RPN const &copy );

		void	calculate( std::string const &arg );
		double	operation( char const &c, double const &a,
			double const &b );

		class	ErrorException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

#endif