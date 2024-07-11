/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:54:33 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/11 11:50:43 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <deque>
# include <iomanip>
# include <sstream>
# include <iostream>

# define K 6

class PmergeMe
{
	private:
		size_t			_size;
		std::list<int>	_list;
		std::deque<int>	_deque;

		std::list<int>	&getList( void );
		std::deque<int>	&getDeque( void );

		bool	onlyNumbers( std::string str );
		bool	duplicateNumber( int const &num );
		void	pushNumbers( int argc, char **argv );

		void	setSize( size_t const &size );
		void	setList( std::list<int> const &list );
		void	setDeque( std::deque<int> const &deque );

		template<typename T>
		void	merge( T &array, int const &start,
			int const &middle, int const &end );
		template<typename T>
		void	printArray( T &array, std::string const &str );
		template<typename T>
		void	insert(T &array, int const &start, int const &end );
		template<typename T>
		void	mergeSort( T &array, int const &start, int const &end );
	public:
		PmergeMe( void );
		~PmergeMe( void );
		PmergeMe( PmergeMe const &copy );
		PmergeMe( int argc, char **argv );

		PmergeMe const	&operator=( PmergeMe const &copy );

		size_t const	&getSize( void ) const;
		std::list<int> const	&getList( void ) const;
		std::deque<int> const	&getDeque( void ) const;

		class	ErrorException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

#endif