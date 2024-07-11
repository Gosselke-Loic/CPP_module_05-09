/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:36:07 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/05 10:34:47 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void )
{}

Serializer::~Serializer( void )
{}

Serializer::Serializer( Serializer const &copy )
{
	*this = copy;
}

Serializer const    &Serializer::operator=( Serializer const &copy )
{
    (void)copy;
    return (*this);
}

Data	*Serializer::deserialize( uintptr_t raw )
{
	return (reinterpret_cast<Data *>(raw));
}

uintptr_t	Serializer::serialize( Data *ptr )
{
	return (reinterpret_cast<uintptr_t>(ptr));
}