/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:15:23 by lgosselk          #+#    #+#             */
/*   Updated: 2024/06/28 09:35:39 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack( void )
{}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack( void ): std::stack<T>()
{}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack( MutantStack const &copy )
{
	*this = copy;
}

template<typename T, typename Container>
MutantStack<T, Container> const   &MutantStack<T, Container>::operator=(
	MutantStack const &copy )
{
	if (this != &copy)
		std::stack<T, Container>::operator=(copy);
	return (*this);
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return (this->c.end());
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

#endif