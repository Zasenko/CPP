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

class Contact
{
	public:
		Contact();
		Contact(
			std::string first_name_ = "",
			std::string last_name_ = "",
			std::string nickname_ = "",
			std::string phone_ = "",
			std::string secret_ = ""
        );
		~Contact();
        void add_first_name(std::string first_name_);
        void add_last_name(std::string last_name_);
        void add_nickname(std::string nickname_);
        void add_phone(std::string phone_);
        void add_secret(std::string secret_);
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone;
		std::string secret;
};

Contact::Contact()
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone = "";
	secret = "";
}

Contact::Contact(
    std::string first_name_,
    std::string last_name_,
    std::string nickname_,
    std::string phone_,
    std::string secret_)
{
	first_name = first_name_;
	last_name = last_name_;
	nickname = nickname_;
	phone = phone_;
	secret = secret_;
}

Contact::~Contact()
{
}

void Contact::add_first_name(std::string first_name_)
{
}

void Contact::add_last_name(std::string last_name_)
{
}

void Contact::add_nickname(std::string nickname_)
{
}

void Contact::add_phone(std::string phone_)
{
}

void Contact::add_secret(std::string secret_)
{
}