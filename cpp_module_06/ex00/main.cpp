/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:36:41 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/03 10:20:19 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cout << "This program need at least 1 argument" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}