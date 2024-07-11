/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:35:54 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/10 10:32:35 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::~Span( void )
{}

Span::Span( void ): _size(0), _container(0)
{}

Span::Span( unsigned int const &size ): _size(size)
{}

Span::Span( Span const &copy ): _size(copy.getSize()), _container(copy.getSize())
{}

/* operators */

Span const	&Span::operator=( Span const &copy )
{
	if (this != &copy)
	{
		this->setSize(copy.getSize());
		this->setContainer(copy.getContainer());
	}
	return (*this);
}

/* Setters - Getters */

unsigned int const	&Span::getSize( void ) const
{
	return (this->_size);
}

std::vector<int>	&Span::getContainer( void )
{
	return (this->_container);
}

void	Span::setSize( unsigned int const &size )
{
	this->_size = size;
}

std::vector<int> const	&Span::getContainer( void ) const
{
	return (this->_container);
}

void	Span::setContainer( std::vector<int> const &container )
{
	this->_container = container;
}

/* exceptions */

char const	*Span::NoDistanceException::what() const throw()
{
	return ("No distance is available");
}

char const	*Span::OutOfBoundsException::what() const throw()
{
	return ("Out of bounds");
}

/* Methods */

void	Span::addNumber( int n )
{
	if (this->getContainer().size() < this->getSize())
		this->getContainer().push_back(n);
	else
		throw (OutOfBoundsException());
}

void	Span::addNumber(std::vector<int>::iterator const &begin,
	std::vector<int>::iterator const &end)
{
	if ((this->getContainer().size() + std::distance(begin, end))
		> this->getSize())
		throw (OutOfBoundsException());
	this->getContainer().insert(this->getContainer().end(), begin,
		end);
}

int	Span::longestSpan( void )
{
	if (this->getContainer().size() < 2)
		throw (NoDistanceException());
	std::vector<int> temp = this->getContainer();
	std::sort(temp.begin(), temp.end());
	int	res = temp[temp.size() - 1] - temp[0];
	return (res);
}

int	Span::shortestSpan( void )
{
	if (this->getContainer().size() < 2)
		throw (NoDistanceException());
	std::vector<int> temp = this->getContainer();
	std::sort(temp.begin(), temp.end());
	int	shortest = temp[1] - temp[0];
	for(std::size_t i = 1; i < temp.size(); i++)
	{
		if ((temp[i] - temp[i - 1]) < shortest)
			shortest = temp[i] - temp[i - 1];
	}
	return (shortest);
}