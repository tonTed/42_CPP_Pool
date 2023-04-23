//
// Created by Teddy BLANCO on 2023-04-23.
//

#include <list>
#include <array>
#include <string>

#include "../Log.hpp"

#ifndef PMERGEME_HPP
#define PMERGEME_HPP


class PmergeMe {

public:
	PmergeMe(char **av, int ac);
	~PmergeMe();


private:
	PmergeMe & operator=(const PmergeMe & rhs);
	PmergeMe(const PmergeMe & rhs);
	PmergeMe();

};


#endif //PMERGEME_HPP
