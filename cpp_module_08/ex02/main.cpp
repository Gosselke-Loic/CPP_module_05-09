/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:44:33 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/10 10:40:35 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int>	mstack;

    mstack.push(5);
    mstack.push(17);

	// printf 17 
    std::cout << mstack.top() << std::endl;

	// remove 17 
    mstack.pop();

	// only have number 5, size = 1
    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

	// begin is 5 from line 20
    MutantStack<int>::iterator it = mstack.begin();
	// end is 0 from line 35
    MutantStack<int>::iterator ite = mstack.end();
    
	++it; // move pointer to 3 
    --it; // move pointer back to 5
    
	std::cout << "Before while loop" << std::endl;
	while (it != ite)
    {
    	std::cout << *it << std::endl;
    	++it;
    }
	std::cout << "After while loop" << std::endl;

	// test constructor copy and operator = 
    std::stack<int>	s(mstack);
	//std::stack<int>	s = mstack;
	
	//std::cout << s.top() << std::endl;

	/*------------------------------------------------*/

	/*std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::list<int> s(mstack);*/

	return (0);
}