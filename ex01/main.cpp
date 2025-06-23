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
#include "PhoneBook.hpp"

std::string trim(const std::string s)
{
	size_t start = s.find_first_not_of(" \t");
	size_t finish = s.find_last_not_of(" \t");
	if (start == std::string::npos || finish == std::string::npos || start > finish)
		return "";
	return s.substr(start, finish - start + 1);
}

bool is_all_digit(const std::string s)
{
	int size = s.length();
	for (int i = 0; i < size; i++)
	{
		if (!std::isdigit(s[i]))
			return false;	
	}
	return true;
}

bool get_text(std::string &s, const std::string text)
{
	while (s.length() < 1)
	{
		std::cout << text;
		std::getline(std::cin, s);
		if (std::cin.eof())
		{
			std::cout << "\nYou pressed Ctrl+D. Closing program now." << std::endl;
			return false;
		}
		s = trim(s);
	}
	return true;
}

bool get_phone(std::string &s, const std::string text)
{
	while (s.length() < 1)
	{
		std::cout << text;
		std::getline(std::cin, s);
		if (std::cin.eof())
		{
			std::cout << "\nYou pressed Ctrl+D. Closing program now." << std::endl;
			return false;
		}
		std::string trimmed = trim(s);
		if (!is_all_digit(trimmed))
		{
			std::cout << "Wrong phone number (Example: 5555555)" << std::endl;
			s = "";
			continue;
		}
		s = trimmed;
	}
	return true;
}

bool get_info(PhoneBook &phone_book)
{
	std::string first_name = "";
	std::string last_name = "";
	std::string nickname = "";
	std::string phone = "";
	std::string secret = "";

	if (!get_text(first_name, "First name > "))
		return false;
	if (!get_text(last_name, "Last name > "))
		return false;
	if (!get_text(nickname, "Nickname > "))
		return false;
	if (!get_phone(phone, "Phone > "))
		return false;
	if (!get_text(secret, "Secret > "))
		return false;

	Contact new_contact(first_name, last_name, nickname, phone, secret);
	phone_book.add(new_contact);
	std::cout << "Contact " << first_name << " " << last_name << " added!\n";
	return true;
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
			return 0;
		}
		command = trim(command);
		if (command == "ADD")
		{
			if (!get_info(phone_book))
				return 0;
		}
		else if (command == "SEARCH")
		{
			if (!phone_book.search())
				return 0;
		}
		else if (command == "EXIT")
			return 0;
		std::cout << prompt;
	}
	return 0;
}
