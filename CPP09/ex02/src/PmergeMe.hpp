//
// Created by Teddy BLANCO on 2023-04-23.
//

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <deque>
# include <string>
# include <limits>
# include <sys/time.h>

# include "../Log.hpp"

# define THRESHOLD 4

class PmergeMe {

public:
	PmergeMe(char **av, int ac);
	~PmergeMe();


private:
	PmergeMe & operator=(const PmergeMe & rhs);
	PmergeMe(const PmergeMe & rhs);
	PmergeMe();

	std::list<unsigned int>		_listInput;
	std::deque<unsigned int>	_dequeInput;

	void	_fillListInput(char **av, int ac);

	double	_currentTime();

	template<typename T>
	void	_mergeInsertSort(T &container, typename T::iterator begin, typename T::iterator end, int threshold);

	template<typename T>
	void	_merge(T &container, typename T::iterator begin, typename T::iterator mid, typename T::iterator end);
};


#endif //PMERGEME_HPP
