/*
 * CountableB.cpp
 *
 *  Created on: Sep 27, 2021
 *      Author: llanyro
 */

#include "CountableB.hpp"

namespace llcpp {
namespace classCore {

CountableB::CountableB() { this->length = 0; }
CountableB::CountableB(const size_bytes_t& length) { this->length = length; }
CountableB::~CountableB() {}
CountableB::CountableB(const CountableB& other) { this->length = other.length; }
CountableB::CountableB(CountableB&& other) noexcept { this->length = other.length; }
CountableB& CountableB::operator=(const CountableB& other) {
	this->length = other.length;
	return *this;
}
CountableB& CountableB::operator=(CountableB&& other) noexcept {
	this->length = other.length;
	return *this;
}

} /* namespace Classes */
} /* namespace Llanylib */
