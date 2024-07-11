/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:37:06 by lgosselk          #+#    #+#             */
/*   Updated: 2024/06/24 14:19:26 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int num	= std::rand() % 3;

	if (num == 0)
		return (new A());
	else if (num == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Class A identified from pointer" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class B identified from pointer" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class C identified from pointer" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A	&a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Class A identified from reference" << std::endl;
	}
	catch(std::exception const &e)
	{}
	try
	{
		B	&b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Class B identified from reference" << std::endl;
	}
	catch(std::exception const &e)
	{}
	try
	{
		C	&c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Class C identified from reference" << std::endl;
	}
	catch(std::exception const &e)
	{}
}

int	main( void )
{
	std::srand(std::time(NULL));
	
	Base	*first = generate();
	Base	*second = generate();
	Base	*third = generate();

	std::cout << "first: " << std::endl;
	identify(first);
	identify(*first);

	std::cout << "second: " << std::endl;
	identify(second);
	identify(*second);

	std::cout << "third: " << std::endl;
	identify(third);
	identify(*third);

	delete first;
	delete second;
	delete third;
	
	return (0);
}