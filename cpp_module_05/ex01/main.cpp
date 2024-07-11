/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:51:04 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/04 15:41:15 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main( void )
{
	try
	{
		Form		form1("married", 1, 1);
		Bureaucrat	person1("Edgar", 2);

		//std::cout << person1 << std::endl;
		//std::cout << form1 << std::endl;
		person1.gradeUp();
		person1.signForm(form1);
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}