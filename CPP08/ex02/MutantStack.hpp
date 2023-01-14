/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:13:54 by tonted            #+#    #+#             */
/*   Updated: 2023/01/13 21:38:33 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {

public:
	MutantStack(){};

	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack(const MutantStack & src) { *this = src; };

	MutantStack & operator=(const MutantStack & src)
    {
        std::stack<T>::operator=(src);
        return *this;
    };

	iterator	begin() { return this->c.begin(); }
    iterator	end() { return std::stack<T>::c.end(); }

	~MutantStack(){};

};