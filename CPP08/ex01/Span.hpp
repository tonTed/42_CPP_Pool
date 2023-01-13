/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:13:01 by tonted            #+#    #+#             */
/*   Updated: 2023/01/13 18:09:30 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define DEBUG 1

#include <iostream>

class Span {

public:
	Span(unsigned int n);
	Span(Span const & src);

	Span &	operator=(const Span & src);

	~Span(void);

	void	addNumber(int toAdd);

	int	shortestSpan(void);
	int	longestSpan(void);

private:
	Span(void);

	unsigned int	_size;
	unsigned int	_currentElement;

	int				_min;
	int				_max;

	int*			_tab;

};