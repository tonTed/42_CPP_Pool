/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:49:40 by tonted            #+#    #+#             */
/*   Updated: 2022/12/12 21:54:02 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void){

	std::cout << "Brain has been created!" << std::endl;
};

Brain::Brain(Brain const & src){ *this = src; };

Brain::~Brain(void){

	std::cout << "Brain has been destructed!" << std::endl;
};

Brain&	Brain::operator=(Brain const & src){

	if (this != &src){

		for (size_t i = 0; i < 100; i++){
			this->ideas[i] = src.ideas[i];
		}
	}
	return (*this);
};
