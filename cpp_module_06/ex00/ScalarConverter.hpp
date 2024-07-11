/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:40:31 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/03 11:26:04 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include "cmath"
# include <limits>
# include <cstdlib>
# include <iostream>

enum e_types
{
	INT,
	CHAR,
	FLOAT,
	DOUBLE
};

class ScalarConverter
{
	private:
		ScalarConverter( void );
		~ScalarConverter( void );
		ScalarConverter( ScalarConverter const &copy );
		ScalarConverter const	&operator=( ScalarConverter const &copy );
	public:
		static void		convert( std::string const &input );
};

#endif