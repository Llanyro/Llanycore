/*
 * CountableB.hpp
 *
 *  Created on: Sep 27, 2021
 *      Author: llanyro
 */

#ifndef CLASSCORE_COUNTABLEB_HPP_
#define CLASSCORE_COUNTABLEB_HPP_

#include "ICountable.hpp"

namespace llcpp {
namespace classCore {

/*
	Countable class for lists of bytes
*/
class CountableB : public ICountable<size_bytes_t> {
	public:
		CountableB();
		CountableB(const size_bytes_t& size);
		virtual ~CountableB();
		CountableB(const CountableB& other);
		CountableB(CountableB&& other) noexcept;
		CountableB& operator=(const CountableB& other);
		CountableB& operator=(CountableB&& other) noexcept;
};

} /* namespace classCore */
} /* namespace llcpp */

#endif /* CLASSCORE_COUNTABLEB_HPP_ */
