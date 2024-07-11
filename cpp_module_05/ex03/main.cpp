/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:39:50 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/05 10:28:23 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"

void	print_new_line(std::string toPrint)
{
	std::cout << std::endl;
	std::cout << toPrint << std::endl;
	std::cout << std::endl;
}

int	main( void )
{
	std::srand(std::time(NULL));

	try
	{
		Bureaucrat	bureaucrat1("John", 5);
		Bureaucrat	bureaucrat2("Pablo", 137);

		Intern someRandomIntern;

		AForm *form1;
		AForm *form2;
		AForm *form3;

		std::cout << std::endl;
		form1 = someRandomIntern.makeForm("presidential pardon", "Bender"); //sign 25, exec 5
		if (form1)
		{
			bureaucrat1.signForm(*form1);
			bureaucrat1.executeForm(*form1);
			delete form1;
		}
		std::cout << std::endl;
		form2 = someRandomIntern.makeForm("shrubbery creation", "Home"); // sign 145 exec 137
		if (form2)
		{
			bureaucrat1.signForm(*form2);
			bureaucrat1.executeForm(*form2);
			delete form2;
		}
		std::cout << std::endl;
		form3 = someRandomIntern.makeForm("robotomy request", "Someone"); // sign 72 exec 45
		if (form3)
		{
			bureaucrat1.signForm(*form3);
			bureaucrat1.executeForm(*form3);
			delete form3;
		}
		std::cout << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}