//
// Created by Teddy BLANCO on 2023-04-22.
//

#include "RPN.hpp"

RPN::RPN() {	Log::logFunction(__FUNCTION__);
}

RPN::RPN(RPN const & src) {	Log::logFunction(__FUNCTION__);
	*this = src;
}

RPN::~RPN() {	Log::logFunction(__FUNCTION__);
}

RPN & RPN::operator=(RPN const & rhs) {	Log::logFunction(__FUNCTION__);
	if (this != &rhs) {
		// do stuff
	}
	return *this;
}