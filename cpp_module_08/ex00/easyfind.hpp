/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:35:06 by lgosselk          #+#    #+#             */
/*   Updated: 2024/06/26 14:53:57 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

# include <algorithm>
# include <iostream>

class	NotFoundException: public std::exception
{
	public:
		const char	*what() const throw();
};

template<typename T>
void	easyfind(T &container, int n);

#include "easyfind.tpp"

#endif