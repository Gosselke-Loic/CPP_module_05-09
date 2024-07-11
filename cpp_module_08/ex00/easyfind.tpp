/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:35:09 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/10 10:19:17 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include "easyfind.hpp"

char const  *NotFoundException::what() const throw()
{
    return ("No coincidence found");
}

template<typename T>
void    easyfind(T &container, int n)
{
    typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw (NotFoundException());
	std::cout << "Found: " << *it << std::endl;
}

#endif