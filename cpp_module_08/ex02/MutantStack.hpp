/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:38:10 by lgosselk          #+#    #+#             */
/*   Updated: 2024/06/27 15:40:35 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template<typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
	public:
		MutantStack( void );
		~MutantStack( void );
		MutantStack( MutantStack const &copy );

		MutantStack const	&operator=( MutantStack const &copy );
		
		typedef typename Container::iterator iterator;
		iterator	end();
		iterator	begin();
};

#include "MutantStack.tpp"

#endif