/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:00:26 by tonted            #+#    #+#             */
/*   Updated: 2022/12/09 11:20:37 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
	FragTrap( void );
	FragTrap(std::string name);
	FragTrap(FragTrap const & src);
	~FragTrap( void );

	void	highFivesGuys(void);

private:
	
};
