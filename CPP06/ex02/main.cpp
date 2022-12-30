/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:49:23 by tonted            #+#    #+#             */
/*   Updated: 2022/12/30 14:42:08 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <iostream>
#include <sys/_types/_time_t.h>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

void identify(Base *p){

	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p){

	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
}


Base*	generate(void){
	time_t	now = ::time(NULL) % 3;

	switch (now) {
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

int	main(void){

	generate();

	Base *ptr = generate();

	identify(ptr);
	identify(*ptr);


	return 0;
}