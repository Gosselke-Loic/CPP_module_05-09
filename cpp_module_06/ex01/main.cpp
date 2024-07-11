/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:36:54 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/08 11:13:04 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main( void )
{
	uintptr_t	stock;
	Data		toTest;
	Data		*toTest2;

	toTest.name = "Hello";
	toTest.lastName = "Bye";
	toTest.age = 46;
	toTest.email = "asdasd@gmail.com";

	stock = Serializer::serialize(&toTest);
	toTest2 = Serializer::deserialize(stock);
	std::cout << toTest2->email << std::endl;
	if (toTest.name == toTest2->name && toTest.lastName == toTest2->lastName
		&& toTest.age == toTest2->age && toTest.email == toTest2->email)
		std::cout << "success!" << std::endl;
	return (0);
}