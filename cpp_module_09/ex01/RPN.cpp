/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:46:12 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/02 13:09:59 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void )
{}

RPN::~RPN( void )
{}

RPN::RPN( std::string const &arg )
{
	try
	{
		calculate(arg);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

RPN::RPN( RPN const &copy )
{
	*this = copy;
}

/* Methods */

double	RPN::operation( char const &c, double const &a,
	double const &b )
{
	if (c == '+')
		return (a + b);
	if (c == '-')
		return (a - b);
	if (c == '*')
		return (a * b);
	if (c == '/')
		return (a / b);
	return (0);
}

void	RPN::calculate( std::string const &arg )
{
	for (size_t i = 0; i < arg.size(); i++)
	{
		char	c = arg[i];
		if (c == ' ')
			continue ;
		if (isdigit(c))
			this->getStack().push(c - '0');
		else if ((c == '+' || c == '-' || c == '/' || c == '*')
			&& this->getStack().size() >= 2)
		{
			double	a = this->getStack().top();
			this->getStack().pop();
			double	b = this->getStack().top();
			this->getStack().pop();
			this->getStack().push(operation(c, b, a));
		}
		else
			throw (ErrorException());
	}
	if (this->getStack().size() == 1)
		std::cout << this->getStack().top() << std::endl;
	else
		throw (ErrorException());
}

/* Operator */

RPN const	&RPN::operator=( RPN const &copy )
{
	if (this != &copy)
		this->setStack(copy.getStack());
	return (*this);
}

/* Getter - Setter */

std::stack<double> const &RPN::getStack( void ) const
{
	return (this->_stack);
}

std::stack<double>	&RPN::getStack( void )
{
	return (this->_stack);
}

void	RPN::setStack( std::stack<double> const &stack )
{
	this->_stack = stack;
}

/* exception */

char const	*RPN::ErrorException::what() const throw()
{
	return ("Error");
}