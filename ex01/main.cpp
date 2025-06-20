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

void get_info(PhoneBook &phone_book)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone;
	std::string secret;

	//TODO:
	//trim
	//chech is empty?
	//check CTRL+D?

	std::cout << "First name:\n> ";
	std::getline(std::cin, first_name);
	std::cout << "Last name:\n> ";
	std::getline(std::cin, last_name);
	std::cout << "Nickname:\n> ";
	std::getline(std::cin, nickname);
	std::cout << "Phone:\n> ";
	std::getline(std::cin, phone);
	std::cout << "Darkest secret:\n> ";
	std::getline(std::cin, secret);


	Contact new_contact = Contact(first_name, last_name, nickname, phone, secret);
	phone_book.add(new_contact);
}

int main(void)
{
	PhoneBook phone_book;
	std::string command;
	std::string prompt = "Enter one of three command: ADD, SEARCH or EXIT:\n> ";

	std::cout << prompt;
	while(std::getline(std::cin, command))
	{
		std::cout << "command: [" << command << "]\n";
		//trim
		//chech is empty?
		//check CTRL+D?
		if (command == "ADD")
		{
			get_info(phone_book);
		}
		else if (command == "SEARCH")
		{
			phone_book.search();
		}
		else if (command == "EXIT")
		{
			return 0;
		}
		else
		{
			//error
		}
		std::cout << prompt;
	}
	return 0;
}
