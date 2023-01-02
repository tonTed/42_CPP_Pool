/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:11:29 by tonted            #+#    #+#             */
/*   Updated: 2022/12/30 09:15:21 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include <limits>
#include <float.h>

int main()
{
    double max = std::numeric_limits<double>::max();
    double inf = std::numeric_limits<double>::infinity();

    double  test = DBL_MAX + 1;

    std::cout << isinf(test) << std::endl;
 
    if(inf > max)
        std::cout << inf << " is greater than " << max << '\n';
}