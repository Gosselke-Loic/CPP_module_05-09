/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:35:56 by lgosselk          #+#    #+#             */
/*   Updated: 2024/06/21 15:13:56 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

# include "stdint.h"
# include "iostream"

struct Data
{
	std::string	name;
	std::string	lastName;
	std::string	email;
	short		age;
};

class Serializer
{
	private:
		Serializer( void );
		~Serializer( void );
		Serializer( Serializer const &copy );
		Serializer const	&operator=( Serializer const &copy );
	public:
		static Data	*deserialize( uintptr_t raw );
		static uintptr_t	serialize( Data *ptr );
};

#endif