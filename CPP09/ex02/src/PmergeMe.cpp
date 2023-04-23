//
// Created by Teddy BLANCO on 2023-04-23.
//

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av, int ac) {	Log::logFunction(__FUNCTION__);

	(void)av;
	(void)ac;

}

PmergeMe::PmergeMe() {	Log::logFunction(__FUNCTION__);

}

PmergeMe::~PmergeMe() {	Log::logFunction(__FUNCTION__);

}

PmergeMe::PmergeMe(const PmergeMe &rhs) {	Log::logFunction(__FUNCTION__);
	*this = rhs;
}

PmergeMe & PmergeMe::operator=(const PmergeMe &rhs) {	Log::logFunction(__FUNCTION__);
	if (this != &rhs)
	{

	}
	return *this;
}
