/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:19:58 by dzasenko          #+#    #+#             */
/*   Updated: 2025/06/20 11:20:02 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

std::string trim(std::string s)
{
	size_t start = s.find_first_not_of(" \t");
	size_t finish = s.find_last_not_of(" \t");
	if (start == std::string::npos || finish == std::string::npos || start > finish)
		return "";
	return s.substr(start, finish - start + 1);
}

bool is_all_digit(std::string s)
{
	int size = s.length();
	for (int i = 0; i < size; i++)
	{
		if (!std::isdigit(s[i]))
			return false;	
	}
	return true;
}

void get_info(PhoneBook &phone_book)
{
	std::string first_name = "";
	std::string last_name = "";
	std::string nickname = "";
	std::string phone = "";
	std::string secret = "";

	while (first_name.length() < 1)
	{
		std::cout << "First name: ";
		std::getline(std::cin, first_name);
		if (std::cin.eof())
		{
			std::cout << "\nYou pressed Ctrl+D. Closing program now." << std::endl;
			std::exit(0);
		}
		first_name = trim(first_name);
	}
	while (last_name.length() < 1)
	{
		std::cout << "Last name: ";
		std::getline(std::cin, last_name);
		if (std::cin.eof())
		{
			std::cout << "\nYou pressed Ctrl+D. Closing program now." << std::endl;
			std::exit(0);
		}
		last_name = trim(last_name);
	}
	while (nickname.length() < 1)
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, nickname);
		if (std::cin.eof())
		{
			std::cout << "\nYou pressed Ctrl+D. Closing program now." << std::endl;
			std::exit(0);
		}
		nickname = trim(nickname);
	}
	while (phone.length() < 1)
	{
		std::cout << "Phone: ";
		std::getline(std::cin, phone);
		if (std::cin.eof())
		{
			std::cout << "\nYou pressed Ctrl+D. Closing program now." << std::endl;
			std::exit(0);
		}
		phone = trim(phone);
	}
	while (secret.length() < 1)
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, secret);
		if (std::cin.eof())
		{
			std::cout << "\nYou pressed Ctrl+D. Closing program now." << std::endl;
			std::exit(0);
		}
		secret = trim(secret);
	}
	Contact new_contact = Contact(first_name, last_name, nickname, phone, secret);
	phone_book.add(new_contact);
}

int main(void)
{
	PhoneBook phone_book;
	std::string command;
	std::string prompt = "*** Enter one of three command: ADD, SEARCH or EXIT: ***\n> ";
	std::cout << prompt;
	while(std::getline(std::cin, command))
	{
		if (std::cin.eof())
		{
			std::cout << "\nYou pressed Ctrl+D. Closing program now." << std::endl;
			std::exit(0);
		}
		command = trim(command);
		if (command == "ADD")
			get_info(phone_book);
		else if (command == "SEARCH")
			phone_book.search();
		else if (command == "EXIT")
			return 0;
		std::cout << prompt;
	}
	return 0;
}
