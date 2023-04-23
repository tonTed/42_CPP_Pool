//
// Created by Teddy BLANCO on 2023-04-23.
//

#include "../Log.hpp"

#ifndef PMERGEME_HPP
#define PMERGEME_HPP


class PmergeMe {

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe & rhs);

	PmergeMe & operator=(const PmergeMe & rhs);

};


#endif //PMERGEME_HPP
