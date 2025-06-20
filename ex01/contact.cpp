/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:39:14 by dzasenko          #+#    #+#             */
/*   Updated: 2025/06/20 11:39:16 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact()
{
	_first_name = "";
	_last_name = "";
	_nickname = "";
	_phone = "";
	_secret = "";
}

Contact::Contact(
    std::string first_name,
    std::string last_name,
    std::string nickname,
    std::string phone,
    std::string secret)
{
	_first_name = first_name;
	_last_name = last_name;
	_nickname = nickname;
	_phone = phone;
	_secret = secret;
}

Contact::~Contact()
{
}

void Contact::print()
{
    //index, first name, last name and nickname
    std::cout << _first_name << ", " << _last_name << std::endl;
}

void Contact::print_all()
{
    std::cout << "First name: " << _first_name << std::endl;
    std::cout << "Last name: " << _last_name << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone: " << _phone << std::endl;
    std::cout << "Decret: " << _secret << std::endl;
}