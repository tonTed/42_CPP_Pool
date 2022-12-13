/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:44:51 by tonted            #+#    #+#             */
/*   Updated: 2022/12/12 22:18:36 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

public:
	Cat(void);
	Cat(Cat const & src);
	~Cat(void);

	Cat&	operator=(Cat const & src);

	void	makeSound(void) const;

private:
	Brain	*_brain;

};
