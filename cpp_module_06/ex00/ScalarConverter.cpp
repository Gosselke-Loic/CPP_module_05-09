/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:48:17 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/08 11:08:13 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{}

ScalarConverter::~ScalarConverter( void )
{}

ScalarConverter::ScalarConverter( ScalarConverter const &copy )
{
	*this = copy;
}

ScalarConverter const	&ScalarConverter::operator=( ScalarConverter const &copy )
{
	(void)copy;
	return (*this);
}

/* Helpers */

static int	checkType( std::string const &str )
{
	char	*check;

	if (str.empty())
		return (-1);
	if (str.size() == 1 && !isdigit(str[0]))
		return (CHAR);
	long long value = std::strtoll(str.c_str(), &check, 10);
	if (*check == '\0')
	{
		if (value < std::numeric_limits<int>::min()
			|| value > std::numeric_limits<int>::max())
			return (-1);
		else
			return (INT);
	}
	std::strtof(str.c_str(), &check);
	if (check[0] == 'f' && !check[1])
		return (FLOAT);
	std::strtod(str.c_str(), &check);
	if (*check == '\0')
		return (DOUBLE);
	return (-1);
}

static bool	checkPrecision( std::string const input )
{
	bool	findPoint = false;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == '.')
		{
			findPoint = true;
			for (size_t j = i + 1; j < input.size(); j++)
			{
				if (input[j] == '0' && (j - i) < 5)
					continue ;
				if (input[j] != '0' && (j - i) < 5)
					break ;
				else
				{
					return (true);
					break ;
				}
			}
		}
		if (findPoint)
			break ;
	}
	if (!findPoint && isdigit(input[0]))
		return (true);
	return (false);
}

/* Method */

void	ScalarConverter::convert( std::string const &input )
{
	int		intValue;
	char	charValue;
	float	floatValue;
	double	doubleValue;

	bool	validInput = true;
	bool	addPrecision = false;

	int	type = checkType(input);
	if (type == 0)
	{
		intValue = std::strtol(input.c_str(), NULL, 10);
		charValue = static_cast<char>(intValue);
		floatValue = static_cast<float>(intValue);
		doubleValue = static_cast<double>(intValue);
	}
	else if (type == 1)
	{
		charValue = input[0];
		intValue = static_cast<int>(charValue);
		floatValue = static_cast<float>(charValue);
		doubleValue = static_cast<double>(charValue);
	}
	else if (type == 2)
	{
		floatValue = std::strtof(input.c_str(), NULL);
		intValue = static_cast<int>(floatValue);
		charValue = static_cast<char>(floatValue);
		doubleValue = static_cast<double>(floatValue);
	}
	else if (type == 3)
	{
		doubleValue = std::strtod(input.c_str(), NULL);
		intValue = static_cast<int>(doubleValue);
		charValue = static_cast<char>(doubleValue);
		floatValue = static_cast<float>(doubleValue);
	}
	else
	{
		floatValue = std::numeric_limits<float>::quiet_NaN();
		doubleValue = std::numeric_limits<double>::quiet_NaN();
		validInput = false;
	}

	if (type == CHAR
		|| (doubleValue - intValue) == 0)
		addPrecision = true;
	else
		addPrecision = checkPrecision(input);

	if (!validInput || intValue < 0 || intValue > 127)
		std::cout << "char: impossible" << std::endl;
	else if (intValue < 32 || intValue > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << charValue << "'" << std::endl;
	if (validInput && doubleValue > -2147483649.0 && doubleValue < 2147483648.0)
		std::cout << "int: " << intValue << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (addPrecision)
	{
		std::cout << "float: " << floatValue << ".0" << "f" << std::endl;
		std::cout << "double: " << doubleValue << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << floatValue << "f" << std::endl;
		std::cout << "double: " << doubleValue << std::endl;
	}
}
