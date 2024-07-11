/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:51:44 by lgosselk          #+#    #+#             */
/*   Updated: 2024/06/26 11:17:23 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template<typename T>
Array<T>::~Array( void )
{
	if (this->getArray())
		delete[] this->getArray();
}

template<typename T>
Array<T>::Array( void ): _size(0), _array(NULL)
{}

template<typename T>
Array<T> const	&Array<T>::operator=( Array const &copy )
{
	if (this != &copy)
	{
		if (this->getArray())
			delete[] this->getArray();
		this->setArray(new T[copy.getSize()]);
		for (size_t i = 0; i < copy.getSize(); i++)
			this->setArrayAt(i, this->getArrayAt(i));
		this->setSize(copy.getSize());
	}
	return (*this);
}

template<typename T>
T	&Array<T>::operator[]( int const index )
{
	if (index < 0 || index >= static_cast<int>(this->getSize()))
		throw (Array::OutOfBoundsException());
	return (this->getArrayAt(index));
}

template<typename T>
Array<T>::Array( Array const &copy ): _size(copy.getSize()),
	_array(new T[copy.getSize()])
{
	for (size_t i = 0; i < copy.getSize(); i++)
		this->setArrayAt(i, copy.getArrayAt(i));
}

template<typename T>
Array<T>::Array( unsigned int const &n ): _size(n), _array(new T[n])
{}

template<typename T>
char const  *Array<T>::OutOfBoundsException::what( void ) const throw()
{
	return ("Index is out of bounds");
}

/* Method */

template<typename T>
unsigned int	Array<T>::size( void ) const
{
	return (this->getSize());
}

/* Setters - Getters */

template<typename T>
T const	*Array<T>::getArray( void ) const
{
	return (this->_array);
}

template<typename T>
void	Array<T>::setArray( T const *&arr )
{
	this->_array = arr;
}

template<typename T>
unsigned int	Array<T>::getSize( void ) const
{
	return (this->_size);
}

template<typename T>
void	Array<T>::setSize( unsigned int const &size )
{
	this->_size = size;
}

template<typename T>
T	&Array<T>::getArrayAt( int const &index ) const
{
	return (this->_array[index]);
}

template<typename T>
void	Array<T>::setArrayAt( int const &index, T data )
{
	this->_array[index] = data;
}

#endif