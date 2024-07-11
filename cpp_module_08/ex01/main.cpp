/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:35:23 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/10 10:32:52 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main( void )
{
	//std::srand(std::time(NULL));
	Span	sp = Span(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		//sp.addNumber(13);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);

	/*------------------------------------------------*/
	
	/*Span	sp = Span(15000);
	std::vector<int> cont;

	for (int i = 0; i < 15000; i++)
		cont.push_back(rand());
	try
	{
		sp.addNumber(cont.begin(), cont.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}*/
	return (EXIT_SUCCESS);
}