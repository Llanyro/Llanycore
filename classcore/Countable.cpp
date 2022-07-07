/*
 * Countable.cpp
 *
 *  Created on: Sep 27, 2021
 *      Author: llanyro
 */

#include "Countable.hpp"

namespace llcpp {
namespace classCore {

Countable::Countable() { this->length = 0; }
Countable::Countable(const len_t& length) { this->length = length; }
Countable::~Countable() {}
Countable::Countable(const Countable& other) { this->length = other.length; }
Countable::Countable(Countable&& other) noexcept { this->length = other.length; }
Countable& Countable::operator=(const Countable& other) {
	this->length = other.length;
	return *this;
}
Countable& Countable::operator=(Countable&& other) noexcept {
	this->length = other.length;
	return *this;
}

} /* namespace classCore */
} /* namespace llcpp */
