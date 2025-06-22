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
    std::cout << "Пока Contact" << _first_name <<"\n";
}

std::string check_len_10(std::string s)
{
    int size = s.length();
    if (size > 10)
    {
        std::string new_s = s.substr(0, 10);
        new_s[9] = '.';
        return new_s;
    }
    else
        return s;
}

void Contact::print(int i)
{
    std::cout << std::setw(10) << std::right << i;
    std::cout << "|";
    std::cout << std::setw(10) << std::right << check_len_10(_first_name);
    std::cout << "|";
    std::cout << std::setw(10) << std::right << check_len_10(_last_name);
    std::cout << "|";
    std::cout << std::setw(10) << std::right << check_len_10(_nickname) << std::endl;
}

void Contact::print_all()
{
    std::cout << "First name: " << _first_name << std::endl;
    std::cout << "Last name: " << _last_name << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone: " << _phone << std::endl;
    std::cout << "Decret: " << _secret << std::endl;
}
