/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:44:51 by tonted            #+#    #+#             */
/*   Updated: 2022/12/12 20:05:24 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal {

public:
	Cat(void);
	Cat(Cat const & src);
	~Cat(void);

	Cat&	operator=(Cat const & src);

	void	makeSound(void) const;
};
