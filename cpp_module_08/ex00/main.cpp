/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:19:41 by lgosselk          #+#    #+#             */
/*   Updated: 2024/06/27 09:52:49 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>

int main( void )
{
	std::vector<int> vect;
	std::deque<int> deque;

	for (int i = 0; i < 5; i++)
	{
		vect.push_back(i);
		deque.push_back(i);
	}

	try
	{
		::easyfind(vect, 4);
		::easyfind(vect, 2);
		::easyfind(deque, 4);
		::easyfind(deque, 10);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}