/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:51:04 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/05 09:48:41 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

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
		ShrubberyCreationForm	form1("Home"); // sign: 145, exec: 137
		PresidentialPardonForm	form2("Google"); // sign:25, exec: 5
		RobotomyRequestForm		form3("Elon Musk"); // sign: 72, exec: 45

		Bureaucrat	bureaucrat1("Jack", 14);
		Bureaucrat	bureaucrat2("John", 30);
		Bureaucrat	bureaucrat3("Coraline", 1);
		Bureaucrat	bureaucrat4("Napoleon", 149);

		print_new_line("Test Shrubbery");
		//bureaucrat4.signForm(form1); // don't work
		bureaucrat2.signForm(form1);
		bureaucrat2.executeForm(form1);
		/*try
		{
			form1.execute(bureaucrat2);
		}
		catch(std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}*/
		

		print_new_line("Test Robotomy");
		//bureaucrat4.signForm(form3); // don't work
		bureaucrat2.signForm(form3);
		bureaucrat2.executeForm(form3);
		//bureaucrat1.executeForm(form3);
		//bureaucrat3.executeForm(form3);
		/*try
		{
			form3.execute(bureaucrat2);
		}
		catch(std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}*/


		print_new_line("Test PresidentPardon");
		//bureaucrat4.signForm(form2); // don't work
		bureaucrat1.signForm(form2);
		bureaucrat3.executeForm(form2);
		/*try
		{
			form2.execute(bureaucrat3);
		}
		catch(std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}*/
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}