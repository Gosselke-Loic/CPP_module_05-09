/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:26:40 by lgosselk          #+#    #+#             */
/*   Updated: 2024/06/25 11:56:57 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template<typename T>
void print(T const &param)
{
	std::cout << param << std::endl;
}

int	main( void )
{
	int			array[] = { 1, 2, 3, 4, 5 };
	char		array2[] = { 'a', 'b', 'c' };
	std::string	array3[] = { "Hello", "Salut", "Hola" };

	::iter(array, 5, &print);
	::iter(array2, 3, &print);
	::iter(array3, 3, &print);
	return (0);
}