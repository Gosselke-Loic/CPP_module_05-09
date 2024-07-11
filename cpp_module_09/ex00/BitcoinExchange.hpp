/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:10:43 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/01 14:02:53 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <sstream>
# include <fstream>
# include <iostream>
# include <algorithm>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;

		void	readDataFile();
	public:
		BitcoinExchange( void );
		~BitcoinExchange( void );
		BitcoinExchange( std::string const &filePath );
		BitcoinExchange( BitcoinExchange const &copy );

		BitcoinExchange const	&operator=( BitcoinExchange const &copy );

		std::map<std::string, double>	&getData( void );
		double const	&getValue( std::string const &date );
		std::map<std::string, double> const	&getData( void ) const;
		void	setData( std::map<std::string, double> const &data );
		void	insertData( std::string const &date, double const &value );

		void	isValidDate( std::string const &date );
		bool	isValidDate2( std::string const &date );
		double	isValidValue( std::string const & value );
		void	printResult( std::string const &date, double const &value );

		class	FileException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	EmptyFileException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	InvalidDateException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	InvalidValueException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	NotPositiveException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	BadInputException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	TooLongException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	TooEarlyDateException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

# endif