/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:35:45 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/09 14:13:48 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <ctime>
# include <vector>
# include <iostream>
# include <algorithm>

class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_container;
	public:
		Span( void );
		~Span( void );
		Span( Span const &copy );
		Span( unsigned int const &size );

		void	addNumber( int n );
		int		longestSpan( void );
		int		shortestSpan( void );
		void	addNumber( std::vector<int>::iterator const &begin,
			std::vector<int>::iterator const &end );

		Span const	&operator=( Span const &copy );

		unsigned int const	&getSize( void ) const;
		void				setSize( unsigned int const &size );

		std::vector<int>		&getContainer( void );
		std::vector<int> const	&getContainer( void ) const;
		void					setContainer( std::vector<int> const &container );

		class	OutOfBoundsException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	NoDistanceException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

#endif