//
// Created by Teddy BLANCO on 2023-04-23.
//

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av, int ac) {	Log::logFunction(__FUNCTION__);

	double	listTime;
	double	dequeTime;

	try {
		_fillListInput(av, ac);
		Log::logContainer(_listInput, "Before<List> ");
		Log::logContainer(_dequeInput, "Before<Deque>");

		listTime = _currentTime();
		_mergeInsertSort<std::list<unsigned int> >( _listInput.begin(), _listInput.end(), THRESHOLD);
		listTime = _currentTime() - listTime;

		dequeTime = _currentTime();
		_mergeInsertSort<std::deque<unsigned int> >( _dequeInput.begin(), _dequeInput.end(), THRESHOLD);
		dequeTime = _currentTime() - dequeTime;

		Log::logContainer(_listInput, "After<List> ");
		Log::logContainer(_dequeInput, "After<Deque>");

		std::cout << GREEN << "Time to process a range of " << _listInput.size() << " elements with std::list  : " << RESET << std::fixed << listTime << " ms." << std::endl;
		std::cout << GREEN << "Time to process a range of " << _dequeInput.size() << " elements with std::deque : " << RESET << std::fixed << dequeTime << " ms." << std::endl;
	}
	catch (std::exception & e) {
		std::cout << RED << "Error: " << RESET << e.what() << std::endl;
		return;
	}
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
		this->_listInput = rhs._listInput;
		this->_dequeInput = rhs._dequeInput;
	}
	return *this;
}

void	PmergeMe::_fillListInput(char **av, int ac) {	Log::logFunction(__FUNCTION__);

	(void)_listInput;
	(void)_dequeInput;

	av++;
	while (--ac)
	{
		try {
			int a = std::stoi(*av);

			if (a < 0)
				throw std::out_of_range("Number out of range: " + std::to_string(a));
			_listInput.push_back(static_cast<unsigned int>(a));
			_dequeInput.push_back(static_cast<unsigned int>(a));
		}
		catch (std::exception & e) {
			throw std::runtime_error(e.what());
		}
		av++;
	}
}

double	PmergeMe::_currentTime() {	Log::logToConsole(__FUNCTION__);
	struct timeval currentTime;
	gettimeofday(&currentTime, nullptr);
	return static_cast<double>(currentTime.tv_sec) + (static_cast<double>(currentTime.tv_usec) / 1000000.0);
}

template<typename T>
void	PmergeMe::_merge(typename T::iterator begin, typename T::iterator mid, typename T::iterator end) {	Log::logFunction(__FUNCTION__);

	// Copy tabs
	T	tab1(begin, mid);
	T	tab2(mid, end);

	// Merge two tabs into container
	typename T::iterator it1 = tab1.begin();
	typename T::iterator it2 = tab2.begin();

	while (it1 != tab1.end() && it2 != tab2.end()) {
		if (*it1 < *it2)
			*begin = *(it1++);
		else
			*begin = *(it2++);
		++begin;
	}

	while (it1 != tab1.end())
	{
		*begin = *(it1++);
		begin++;
	}

	while (it2 != tab2.end())
	{
		*begin = *(it2++);
		begin++;
	}
}

template<typename T>
void	PmergeMe::_insertion(typename T::iterator begin, typename T::iterator end) {	Log::logFunction(__FUNCTION__);

	if (begin == end)
		return;

	unsigned int	tmp;

	for (typename T::iterator it = begin; it != end; it++)
	{
		typename T::iterator prev;
		typename T::iterator cur = it;
		if (cur != begin)
			prev = std::prev(cur);
		while (cur != begin && *prev > *cur)
		{
			tmp = *prev;
			*prev = *cur;
			*cur = tmp;
			cur--;
			prev = std::prev(cur);
		}
	}
}

template<typename T>
void 	PmergeMe::_mergeInsertSort( typename T::iterator begin, typename T::iterator end, int threshold) {	Log::logFunction(__FUNCTION__);

	if (std::distance(begin, end) < threshold)
		_insertion<T>(begin, end);
	else
	{
		typename T::iterator mid = std::next(begin, std::distance(begin, end) / 2);
		_mergeInsertSort<T>(begin, mid, THRESHOLD);
		_mergeInsertSort<T>(mid, end, THRESHOLD);
		_merge<T>(begin, mid, end);
	}
}
