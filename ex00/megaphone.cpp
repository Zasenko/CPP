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

// int main(int ac, char *av[])
int main(void)
{
    using namespace std;
    // cout << "\a Operation \" Hyper Hype \" is now activated ! \n";
    // cout << "Enter your agent code:__________\b\b\b\b\b\b\b\b\b";
    // long code;
    // cin >> code;
    // cout << "\aYou entered [" << code << "] ...\n";
    // cout << "\aCode ver i fied ! Proceed with Plan ZЗ!\n";

    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tub = 10.0 / 3.0;
    double mint = 10.0 / 3.0;
    const float million = 1.0e6;
    cout << " tub = " << tub;
    cout << ", а million tubs = " << million * tub;
    cout << ",\nand ten million tubs = ";
    cout << 10 * million * tub << endl;
    cout << "mint = " << mint << " and а mill ion mints = ";
    cout << million * mint << endl;
    return 0;

    // char alarm = 7;
    // std::cout << alarm << "Don't do that again !\a\n";

    // char c;
    // std::cout << "Enter CHAR:" << std::endl;
    // std::cin >> c;
    // std::cout << "[" << c << "]" << std::endl;
    // std::cout.put('f');

    // if (ac < 2)
    //     std::cout
    //         << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

    // int i = 1;
    // while(av[i])
    // {
    //     ft_strupcase(av[i]);
    //     if (i++ < ac)
    //         std::cout << " ";
    // }
    // std::cout << std::endl;

    // return 0;
}
//c++ -Wall -Wextra -Werror -std=c++98 megaphone.cpp
//