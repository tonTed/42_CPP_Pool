/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:44:51 by tonted            #+#    #+#             */
/*   Updated: 2022/12/12 21:35:32 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:
	WrongCat(void);
	WrongCat(WrongCat const & src);
	~WrongCat(void);

	WrongCat&	operator=(WrongCat const & src);

	void	makeSound(void) const;
};
