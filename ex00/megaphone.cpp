#include <iostream>
#include <stdio.h>

void ft_strupcase(char *str)
{
    // if (!str)
    //     exit(1);
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str = *str - 32;
		}
        std::cout << *str;
		str++;
	}
}

int main(int ac, char *av[])
{
    
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    
    int i = 1;
    while(av[i])
    {
        ft_strupcase(av[i]);
        if (i++ < ac)
            std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}
//c++ -Wall -Wextra -Werror -std=c++98 megaphone.cpp 