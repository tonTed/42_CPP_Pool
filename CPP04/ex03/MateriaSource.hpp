/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:21:33 by tblanco           #+#    #+#             */
/*   Updated: 2022/12/14 21:40:31 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	
public:
	MateriaSource(void);
	MateriaSource(MateriaSource const & src);
	~MateriaSource(void);

	MateriaSource&	operator=(MateriaSource const & src);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

private:
	AMateria*	_inventory[4];
	
};
