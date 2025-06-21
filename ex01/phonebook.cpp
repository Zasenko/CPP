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

PhoneBook::PhoneBook()
{
	_i = 0;
	_is_full = false;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add(Contact contact)
{
	_contacts[_i] = contact;
	_i++;
	if (_i == 8)
	{
		_i = 0;
		_is_full = true;
	}
}

void PhoneBook::search()
{
	if (!_is_full && _i == 0)
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return;
	}
	
	int count = _is_full ? 8 : _i;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	int i = 0;

	while (i < count)
	{
		_contacts[i].print(i + 1);
		i++;
	}
	std::cout << "Select user:\n> ";

	std::string index;
	std::getline(std::cin, index);

	// TODO:
	// trim
	// chech is empty?
	// check CTRL+D?
	// number 1-8;
	_contacts[i - 1].print_all();
}

int PhoneBook::get_i()
{
	return _i;
}