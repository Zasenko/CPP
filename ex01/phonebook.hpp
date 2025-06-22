/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:53:31 by dzasenko          #+#    #+#             */
/*   Updated: 2025/06/20 12:53:33 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
	private:
		int _i;
		bool _is_full;
		Contact _contacts[8];
	public:
		PhoneBook();
		~PhoneBook();
		void add(Contact &contact);
		void search();
		int get_i();
};

#endif