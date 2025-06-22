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

void get_line(std::string &s, const std::string text)
{
	while (s.length() < 1)
	{
		std::cout << text;
		std::getline(std::cin, s);
		if (std::cin.eof())
		{
			std::cout << "\nYou pressed Ctrl+D. Closing program now." << std::endl;
			std::exit(0);
		}
		std::string d = trim(s);
		s = d;
	}
}

void get_info(PhoneBook &phone_book)
{
	std::string first_name = "";
	std::string last_name = "";
	std::string nickname = "";
	std::string phone = "";
	std::string secret = "";

	get_line(first_name, "First name: ");
	get_line(last_name, "Last name: ");
	get_line(nickname, "Nickname: ");
	get_line(phone, "Phone: ");
	get_line(secret, "Secret: ");

	Contact new_contact(first_name, last_name, nickname, phone, secret);
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
			return 0;
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
