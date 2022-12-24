/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:32:12 by tonted            #+#    #+#             */
/*   Updated: 2022/12/24 10:04:49 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

namespace ft {
	void	toUpper(char *s){
		for (size_t i = 0; i < strlen(s); i++)
			s[i] = toupper(s[i]);
	}
}

int main(int ac, char **av)
{
	for (size_t i = 1; i < ac; i++){
		ft::toUpper(av[i]);
		std::cout << av[i];
	}
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return 0;
}
