/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:03:21 by dzasenko          #+#    #+#             */
/*   Updated: 2025/06/20 12:03:23 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_i = 0;
	_is_full = false;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add(Contact &contact)
{
	_contacts[_i] = contact;
	_i++;
	if (_i == 8)
	{
		_i = 0;
		_is_full = true;
	}
}

bool PhoneBook::search()
{
	if (!_is_full && _i == 0)
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return true;
	}
	
	int count = _is_full ? 8 : _i;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << std::setw(10) << std::right << "INDEX";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "FIRST NAME";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "LAST NAME";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "NICKNAME" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	int i = 0;
	while (i < count)
	{
		_contacts[i].print(i + 1);
		i++;
	}
	std::cout << "-------------------------------------------" << std::endl;
	while (1)
	{
		std::cout << "Enter user index > ";
		std::string index;
		std::getline(std::cin, index);
		if (std::cin.eof())
		{
			std::cout << "\nYou pressed Ctrl+D. Closing program now." << std::endl;
			return false;
		}
		index = trim(index);
		if (index.empty())
			continue;
		if (!is_all_digit(index))
		{
			std::cout << "Index schould be number (1 ... 8)!\n";
			continue;
		}
		if (index.length() != 1)
		{
			std::cout << "Index is out of range!\n";
			continue;
		}
		int num = index[0] - '0';
		if (_is_full)
		{
			if (num > 0 && num < 9)
			{
				_contacts[num - 1].print_all();
				break;
			}
			else
			{
				std::cout << "Index is out of range!\n";
				continue;
			}
		}
		else
		{
			if (num > 0 && (num - 1) < _i)
			{
				_contacts[num - 1].print_all();
				break;
			}
			else
			{
				std::cout << "Index is out of range!\n";
				continue;
			}
		}
	}
	return true;
}

int PhoneBook::get_i()
{
	return _i;
}
