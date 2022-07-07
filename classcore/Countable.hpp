/*
 * Countable.hpp
 *
 *  Created on: Sep 27, 2021
 *      Author: llanyro
 */

#ifndef CLASSCORE_COUNTABLE_HPP_
#define CLASSCORE_COUNTABLE_HPP_

#include "ICountable.hpp"

namespace llcpp {
namespace classCore {

/*
	Countable class for classic lists
*/
class Countable : public ICountable<len_t> {
	public:
		Countable();
		Countable(const len_t& length);
		virtual ~Countable();
		Countable(const Countable& other);
		Countable(Countable&& other) noexcept;
		Countable& operator=(const Countable& other);
		Countable& operator=(Countable&& other) noexcept;
};

} /* namespace classCore */
} /* namespace llcpp */

#endif /* CLASSCORE_COUNTABLE_HPP_ */
