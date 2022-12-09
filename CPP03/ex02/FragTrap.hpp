/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:00:26 by tonted            #+#    #+#             */
/*   Updated: 2022/12/08 19:02:17 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
	FragTrap( void );
	FragTrap(FragTrap const & src);
	~FragTrap( void );

	FragTrap &	operator=(FragTrap const & rhs);

	void	highFivesGuys(void);

private:
	
};
