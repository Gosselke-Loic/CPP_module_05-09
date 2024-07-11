/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:08:15 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/08 11:40:42 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <ctime>
# include <cstdlib>
# include <iostream>

template<typename T>
class Array
{
	private:
		unsigned int	_size;
		T				*_array;
	public:
		Array( void );
		~Array( void );
		Array( Array const &copy );
		Array( unsigned int const &n );

		T			&operator[]( int const index );
		Array const	&operator=( Array const &copy );

		unsigned int	getSize( void ) const;
		T const			*getArray( void ) const;
		T				&getArrayAt( int const &index ) const;

		void	setArray( T const *&arr );
		void	setSize( unsigned int const &size );
		void	setArrayAt( int const &index, T data );

		unsigned int	size( void ) const;

		class OutOfBoundsException: public std::exception
		{
			public:
				char const	*what(void) const throw();
		};
};

#include "Array.tpp"

#endif