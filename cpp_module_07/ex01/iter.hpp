/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:38:52 by lgosselk          #+#    #+#             */
/*   Updated: 2024/06/25 10:10:03 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

template <typename T>
void	iter(T *array, int length, void (*funct)(T const &param))
{
	for (int i = 0; i < length; i++)
		funct(array[i]);
}

#endif