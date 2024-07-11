/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:51:04 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/04 15:21:26 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main( void )
{
	try
	{
		Bureaucrat	person1("Edgar", 1);
    	Bureaucrat	*person2 = new Bureaucrat("Mclovin", 151);
		std::cout << person1 << std::endl;
		std::cout << *person2 << std::endl;
		person1.gradeUp();
		person2->gradeDown();
		delete person2;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}