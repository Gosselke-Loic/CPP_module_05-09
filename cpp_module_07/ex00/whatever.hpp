/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:27:33 by lgosselk          #+#    #+#             */
/*   Updated: 2024/06/25 09:37:17 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

template <typename T>
void	swap(T &a, T &b)
{
	T	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T	min(T a, T b)
{
	return ((a < b) ? a : b);
}

template <typename T>
T	max(T a, T b)
{
	return ((a > b) ? a : b);
}

#endif