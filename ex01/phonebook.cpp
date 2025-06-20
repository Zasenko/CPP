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
	contact.print();
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
	int i = 0;

	if (!_is_full && _i == 0)
		return ;
	while (i < (_is_full ? 8 : _i))
	{
		std::cout << i + 1 << ": ";
		_contacts[i++].print();
	}
	std::cout << "Select user:\n> ";
}

int PhoneBook::get_i()
{
	return _i;
}