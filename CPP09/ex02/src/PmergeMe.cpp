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
	T	tab1;
	T	tab2;

	typename T::iterator it;
	for (it = begin; it != mid; ++it)
	{
		Log::logToConsole("Pushing (tab1): " + std::to_string(*it));
		tab1.push_back(*it);
	}
	for (it = mid; it != end; ++it)
	{
		Log::logToConsole("Pushing (tab2): " + std::to_string(*it));
		tab2.push_back(*it);
	}
	Log::logContainer(tab1, "tab1: ");
	Log::logContainer(tab2, "tab2: ");

	// Merge two tabs into container
	typename T::iterator it1 = tab1.begin();
	typename T::iterator it2 = tab2.begin();
	it = begin;

	while (it1 != tab1.end() && it2 != tab2.end()) {
		if (*it1 < *it2) {
			*it = *it1;
			++it1;
		}
		else {
			*it = *it2;
			++it2;
		}
		++it;
	}

	// Copy remaining elements of tab1
	while (it1 != tab1.end()) {
		*it = *it1;
		++it1;
		++it;
	}

	// Copy remaining elements of tab2
	while (it2 != tab2.end()) {
		*it = *it2;
		++it2;
		++it;
	}
}

template<typename T>
void 	PmergeMe::_mergeInsertSort( typename T::iterator begin, typename T::iterator end, int threshold) {	Log::logFunction(__FUNCTION__);

	typename T::iterator mid = std::next(begin, std::distance(begin, end) / 2);

	Log::logToConsole("len tab: " + std::to_string(std::distance(begin, end)));

	if (std::distance(begin, end) <= threshold)
	{
		//insertionSort
	}
	else
	{
		_mergeInsertSort<T>( begin, mid, threshold);
		_mergeInsertSort<T>( std::next(mid), end, threshold);
		_merge<T>( begin, mid ,end);
	}
}
