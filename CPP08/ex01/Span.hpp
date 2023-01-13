/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:13:01 by tonted            #+#    #+#             */
/*   Updated: 2023/01/13 01:22:04 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Span {

public:
	Span(unsigned int n);
	Span(Span const & src);

	Span &	operator=(const Span & src);

	~Span(void);

private:
	Span(void);

	unsigned int	_size;
	int*			_tab;

};