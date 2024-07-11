/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:10:58 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/11 10:32:08 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void )
{}

BitcoinExchange::~BitcoinExchange( void )
{}

BitcoinExchange::BitcoinExchange( std::string const &filePath )
{
    readDataFile();
	std::ifstream	file(filePath.c_str());
	if (!file.is_open())
		throw (FileException());
	std::string	line;
	if (!std::getline(file, line))
	{
		file.close();
		throw (EmptyFileException());
	}
	while (std::getline(file, line))
	{
		std::stringstream	ss(line);
		std::string	date;
		std::string	value;
		std::getline(ss, date, '|');
		date.erase(remove_if(date.begin(), date.end(), isspace), date.end());
		std::getline(ss, value, '\n');
		value.erase(remove_if(value.begin(), value.end(), isspace), value.end());
		try
		{
			if (date.empty() || value.empty())
				throw (BadInputException());
			isValidDate(date);
			printResult(date, isValidValue(value));
		}
		catch (BitcoinExchange::BadInputException const &e)
		{
			std::cerr << e.what() << line << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const &copy )
{
	*this = copy;
}

BitcoinExchange const   &BitcoinExchange::operator=( BitcoinExchange const &copy )
{
	if (this != &copy)
		this->setData(copy.getData());
	return (*this);
}

/* Methods */

bool	BitcoinExchange::isValidDate2( std::string const &date )
{
	int	year, month, day;

	std::istringstream(date.substr(0, 4)) >> year;
	std::istringstream(date.substr(5, 2)) >> month;
	std::istringstream(date.substr(8, 2)) >> day;
	if (year < 1 || (month < 1 || month > 12) || (day < 1 || day > 31))
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0)
		|| (year % 400 == 0)) && day != 29)
		return (false);
	if (month == 2 && !((year % 4 == 0 && year % 100 != 0)
		|| (year % 400 == 0)) && day != 28)
		return (false);
	return (true);
}

void	BitcoinExchange::isValidDate( std::string const &date )
{
	if (date.size() != 10)
		throw (InvalidDateException());
	for (int i = 0; i < 10; i++)
	{
		if ((i == 4 || i == 7) && (date[i] != '-'))
			throw (InvalidDateException());	
		else
		{
			if (date[i] != '-' && !isdigit(date[i]))
				throw (InvalidDateException());
		}
	}
	if (!isValidDate2(date))
		throw (BadInputException());
}

void	BitcoinExchange::printResult( std::string const &date,
	double const &value )
{
	if (this->getData().count(date) > 0)
	{
		std::cout << date << " => " << value << " = " <<
			this->getValue(date) * value << std::endl;
		return ;
	}
	std::map<std::string, double>::iterator it = this->getData().lower_bound(date);
	if (it == this->getData().begin())
		throw (TooEarlyDateException());
	else
	{
		//std::cout << it->first << " | " << it->second << std::endl;
		--it;
		std::cout << date << " => " << value << " = " <<
			it->second * value << std::endl;
	}
}

double	BitcoinExchange::isValidValue( std::string const &value )
{
	double number;
	std::stringstream	ss(value);
	ss >> number;
	if (!ss.eof() && ss.fail())
		throw (InvalidValueException());
	if (number < 0)
		throw (NotPositiveException());
	if (number > 1000)
		throw (TooLongException());
	if (value [0] == '.' || value[value.size() - 1] == '.'
		|| (value[0] == '0' && value.size() > 1 && value[1] != '.'))
		throw (InvalidValueException());
	for (size_t i = 0; i < value.size(); i++)
	{
		if (value[i] != '.' && !isdigit(value[i]) && (value[i] != 'e'
			&& value[i] != 'E'))
			throw (InvalidValueException());
		if ((value[i] == 'e' || value[i] == 'E')
			&& (!value[i + 1] || !isdigit(value[i + 1])))
			throw (InvalidValueException());
	}
	return (number);
}

void	BitcoinExchange::readDataFile( void )
{
	std::ifstream	infile("data.csv");
	if (!infile.is_open())
		throw (FileException());
	std::string	line;
	if (!std::getline(infile, line))
	{
		infile.close();
		throw (EmptyFileException());
	}
	while (std::getline(infile, line))
	{
		std::stringstream	ss(line);
		std::string			date;
		double				value;
		std::getline(ss, date, ',');
		ss >> value;
		this->insertData(date, value);
	}
	infile.close();
}

/* Exceptions */

char const	*BitcoinExchange::FileException::what() const throw()
{
	return ("Error: could not open file.");
}

char const	*BitcoinExchange::EmptyFileException::what() const throw()
{
	return ("Empty file.");
}

char const	*BitcoinExchange::InvalidDateException::what() const throw()
{
	return ("Error: Invalid date format.");
}

char const	*BitcoinExchange::InvalidValueException::what() const throw()
{
	return ("Error: Invalid number.");
}

char const	*BitcoinExchange::NotPositiveException::what() const throw()
{
	return ("Error: not a positive number.");
}

char const	*BitcoinExchange::BadInputException::what() const throw()
{
	return ("Error: bad input => ");
}

char const	*BitcoinExchange::TooLongException::what() const throw()
{
	return ("Error: too large a number.");
}

char const	*BitcoinExchange::TooEarlyDateException::what() const throw()
{
	return ("Error: too early date.");
}

/* Getter - Setter */

std::map<std::string, double>	&BitcoinExchange::getData( void )
{
	return (this->_data);
}

std::map<std::string, double> const	&BitcoinExchange::getData( void ) const
{
	return (this->_data);
}

void	BitcoinExchange::setData( std::map<std::string, double> const &data )
{
	this->_data = data;
}

void	BitcoinExchange::insertData( std::string const &date,
	double const &value )
{
	this->_data[date] = value;
}

double const	&BitcoinExchange::getValue( std::string const &date )
{
	return (this->_data[date]);
}
