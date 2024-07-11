/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:26:10 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/08 11:50:02 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define SIZE 25
#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

/*int	main( void )
{
	std::srand(std::time(NULL));

	Array<int>	array1(SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		const int val = rand();
		array1[i] = val;
	}
	
	{
		Array<int> temp = array1;
		temp[2] = 4;
		std::cout << temp[2] << " - " << array1[2] << std::endl;
	}

	try
	{
		array1[-1] = 2;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		array1[25] = 0;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}*/