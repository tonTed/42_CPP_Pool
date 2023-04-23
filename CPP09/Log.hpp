//
// Created by Teddy BLANCO on 2023-04-20.
//

#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include "colors.hpp"
#include <map>

#define DEBUG 1
#define FUNCTION 1

class Log {
public:

	static void logToConsole(std::string const & str) {
		if (DEBUG)
			std::cout << BLUE << "[DEBUG]    " << RESET << str << std::endl;
	}

	static void logFunction(std::string const & str) {
		if (FUNCTION)
			std::cout << MAGENTA << "[FUNCTION] " << str << RESET << std::endl;
	}

	template<typename map_key, typename map_val>
	static void logMap(std::map<map_key, map_val> const & map) {
		if (DEBUG) {
			std::cout << BLUE << "[DEBUG]    " << RESET << "Map content:" << std::endl;
			for (typename std::map<map_key, map_val>::const_iterator it = map.begin(); it != map.end(); ++it) {
				std::cout << BLUE << "[DEBUG]    " << RESET << it->first << " => " << it->second << std::endl;
			}
		}
	}

	template<typename T>
	static void logContainer(T const & container, std::string prefix)
	{
		std::cout << YELLOW << prefix << ": " << RESET;
		for (typename T::const_iterator it = container.begin(); it != container.end(); it++) {
			std::cout << " " << *it;
		}
		std::cout << std::endl;
	}
};

#endif //LOG_HPP
