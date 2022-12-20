/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:19:51 by tonted            #+#    #+#             */
/*   Updated: 2022/12/20 07:52:24 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
#include <sys/_types/_size_t.h>

#define BAD_INPUT 0x0
#define T_CHAR 0x1
#define T_INT 0x2
#define T_FLOAT 0x4
#define T_DOUBLE 0x8

void print_byte_as_bits(char val) {
  for (int i = 7; 0 <= i; i--) {
    printf("%c", (val & (1 << i)) ? '1' : '0');
  }
  std::cout << std::endl;
}

char	set_type(std::string literal){

	char	flag;

	if (literal.length() == 1){
		if (std::isdigit(literal[0]))
			flag = T_INT;
		else
			flag = T_CHAR;
	}
	else {
		flag = T_INT;

		int i = 0;
		while (flag && literal[i]){
			if (isdigit(literal[i]))
				;
			else if (i && literal[i] == '.' && literal[i + 1]){
				flag &= ~T_INT;
				if (flag &= T_FLOAT | T_DOUBLE)
					flag = BAD_INPUT;
				else
					flag |= T_DOUBLE;
			}
			else if (i && literal[i] == 'f' && !literal[i + 1] && isdigit(literal[i - 1]))
				flag = T_FLOAT;
			else
				flag = BAD_INPUT;
			i++;
		}
	};
	return flag;
}

int	main(int ac, char *av[]){

	char	flag;

	if (ac != 2){
		std::cout << "Bad amounts of arguments(expected 1, given " << ac - 1 << ")" << std::endl;
		return 0;
	}
	flag = set_type(av[1]);
	if (!flag)
		std::cout << "Bad input!" << std::endl;
	
}
