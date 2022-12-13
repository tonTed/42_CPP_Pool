/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:19:03 by tonted            #+#    #+#             */
/*   Updated: 2022/12/12 22:08:57 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
	Animal*	animals[10];

	for (size_t i = 0; i < 10; i++){
		if (i % 2)
			animals[i] = new Cat();
		else 
			animals[i] = new Dog();
	}
	for (size_t i = 0; i < 10; i++){
		delete animals[i];
	}

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;
	
	return (0);
}
