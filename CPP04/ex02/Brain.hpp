/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:42:51 by tonted            #+#    #+#             */
/*   Updated: 2022/12/12 21:44:55 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain {

public:
	Brain(void);
	Brain(Brain const & src);
	~Brain(void);

	Brain& operator=(Brain const & src);

	std::string	ideas[100];
};
