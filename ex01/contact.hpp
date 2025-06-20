/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:53:17 by dzasenko          #+#    #+#             */
/*   Updated: 2025/06/20 12:53:19 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
    private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone;
		std::string _secret;
	public:
		Contact();
		Contact(
			std::string first_name,
			std::string last_name,
			std::string nickname,
			std::string phone,
			std::string secret
        );
		~Contact();
        void print();
        void print_all();
};

#endif