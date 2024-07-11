/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:55:40 by lgosselk          #+#    #+#             */
/*   Updated: 2024/07/04 14:11:27 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void )
{}

PmergeMe::~PmergeMe( void )
{}

PmergeMe::PmergeMe( PmergeMe const &copy )
{
	*this = copy;
}

PmergeMe::PmergeMe( int argc, char **argv )
{
	pushNumbers(argc, argv);
	printArray(this->getList(), "Before: ");
	clock_t	start1 = clock();
	mergeSort(this->getList(), 0, this->getList().size() - 1);
	clock_t	end1 = clock();
	double	time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;
	clock_t	start2 = clock();
	mergeSort(this->getDeque(), 0, this->getDeque().size() - 1);
	clock_t	end2 = clock();
	double	time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;
	printArray(this->getDeque(), "After: ");
	std::cout << "Time to process a range of " << this->getList().size()
		<< " elements with std::list : " << std::fixed << std::setprecision(5)
		<< time1 << " us" << std::endl;
	std::cout << "Time to process a range of " << this->getDeque().size()
		<< " elements with std::deque : " << std::fixed << std::setprecision(5)
		<< time2 << " us" << std::endl;
}

/* Methods */

template<typename T>
void	PmergeMe::insert( T &array, int const &start, int const &end )
{
	typename T::iterator	it = array.begin();
	typename T::iterator	itEnd = array.begin();
	std::advance(it, start);
	std::advance(itEnd, end + 1);
	for (; it != itEnd && it != array.end(); it++)
	{
		typename T::iterator	curr = it;
		typename T::iterator	prev = it;
		typename T::iterator	next = it;
		int	temp = *it;
		++next;
		while (prev != array.begin() && *(--prev) > temp)
		{
			*curr = *prev;
			curr = prev;
		}
		*curr = temp;
		curr = next;
	}
}

template<typename T>
void	PmergeMe::merge( T &array, int const &start, int const &middle,
	int const &end )
{
	T	left;
	T	right;

	typename T::iterator	it = array.begin();
	std::advance(it, start);
	for (int i = start; i <= middle; i++)
	{
		left.push_back(*it);
		++it;
	}
	it = array.begin();
	std::advance(it, middle + 1);
	for (int i = middle + 1; i <= end; i++)
	{
		right.push_back(*it);
		++it;
	}
	it = array.begin();
	typename T::iterator	leftIt = left.begin();
	typename T::iterator	rightIt = right.begin();
	std::advance(it, start);
	while (leftIt != left.end() && rightIt != right.end())
	{
		if (*leftIt <= *rightIt)
		{
			*it = *leftIt;
			++leftIt;
		}
		else
		{
			*it = *rightIt;
			++rightIt;
		}
		++it;
	}
	for (; leftIt != left.end(); ++it, ++leftIt)
		*it = *leftIt;
	for (; rightIt != right.end(); ++it, ++rightIt)
		*it = *rightIt;
}

template<typename T>
void	PmergeMe::mergeSort( T &array, int const &start, int const &end )
{
	if ((end - start) > K)
	{
		size_t middle = (start + end) / 2;
		mergeSort(array, start, middle);
		mergeSort(array, middle + 1, end);
		merge(array, start, middle, end);
	}
	else
		insert(array, start, end);
}

template<typename T>
void	PmergeMe::printArray( T &array, std::string const &str  )
{
	int	i = 0;

	std::cout << str;
	for (typename T::iterator it = array.begin();
		it != array.end(); it++)
	{
		if (i == 4 && array.size() >= 7)
		{
			std::cout << " [...]";
			break ;
		}
		std::cout << *it << " ";
		i++; 
	}
	std::cout << std::endl;
}

bool	PmergeMe::duplicateNumber( int const &num )
{
	for (std::list<int>::iterator it = this->getList().begin();
		it != this->getList().end(); it++)
	{
		if (*it == num)
			return (true);
	}
	/*for (std::deque<int>::iterator it = this->getDeque().begin();
		it != this->getDeque().end(); it++)
	{
		if (*it == num)
			return (true);
	}*/
	return (false);
}

bool	PmergeMe::onlyNumbers( std::string str )
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

void	PmergeMe::pushNumbers( int argc, char **argv )
{
	for (int i = 1; i < argc; i++)
	{
		if (!onlyNumbers(argv[i]))
			throw (ErrorException());
		int					num;
		std::stringstream	ss(argv[i]);
		ss >> num;
		if (num < 0)
			throw (ErrorException());
		//if (duplicateNumber(num))
		//	throw (ErrorException());
		this->getDeque().push_back(num);
		this->getList().push_back(num);
	}
	this->setSize(this->getList().size());
}

/* Operator */

PmergeMe const	&PmergeMe::operator=( PmergeMe const &copy )
{
	if (this != &copy)
	{
		this->setSize(copy.getSize());
		this->setList(copy.getList());
		this->setDeque(copy.getDeque());
	}
	return (*this);
}

/* Getters - Setters */

std::list<int>	&PmergeMe::getList( void )
{
	return (this->_list);
}

std::deque<int>	&PmergeMe::getDeque( void )
{
	return (this->_deque);
}

void	PmergeMe::setSize( size_t const &size )
{
	this->_size = size;
}

size_t const	&PmergeMe::getSize( void ) const
{
	return (this->_size);
}

void	PmergeMe::setList( std::list<int> const &list)
{
	this->_list = list;
}

std::list<int> const	&PmergeMe::getList( void ) const
{
	return (this->_list);
}

std::deque<int> const	&PmergeMe::getDeque( void ) const
{
	return (this->_deque);
}

void	PmergeMe::setDeque( std::deque<int> const &deque )
{
	this->_deque = deque;
}

/* exception */

char const	*PmergeMe::ErrorException::what() const throw()
{
	return ("Error");
}
