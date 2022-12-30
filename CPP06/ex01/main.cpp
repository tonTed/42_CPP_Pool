/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:49:23 by tonted            #+#    #+#             */
/*   Updated: 2022/12/30 10:01:43 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sys/_types/_uintptr_t.h>

typedef struct sData {
	std::string	data;
	int			number;
} Data;

uintptr_t	serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}

int	main(void){

	Data	data;

	data.data = "42 Quebec!";
	data.number = 42;

	std::cout << &data << std::endl;

	uintptr_t	uPtr = serialize(&data);

	std::cout << &uPtr << std::endl;

	std::cout << deserialize(uPtr) << std::endl;
	std::cout << deserialize(uPtr)->data << std::endl;
	std::cout << deserialize(uPtr)->number << std::endl;

	return 0;
}