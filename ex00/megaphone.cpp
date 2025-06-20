/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzasenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:06:28 by dzasenko          #+#    #+#             */
/*   Updated: 2025/06/20 11:06:31 by dzasenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>

unsigned char make_up(unsigned char c)
{
    return std::toupper(c);
}

int main(int ac, char *av[])
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    int i = 1;
    while(av[i])
    {
        std::string s = av[i];
        size_t start = s.find_first_not_of(" \t");
        size_t finish = s.find_last_not_of(" \t");
        if (start == std::string::npos || finish == std::string::npos || start > finish)
        {
            i++;
            continue;
        }
        s = s.substr(start, finish - start + 1);
        std::transform(s.begin(), s.end(), s.begin(), make_up);
        std::cout << s;
        if (i != ac - 1)
            std::cout << " ";
        i++;
    }
    std::cout << std::endl;
    return 0;
}
