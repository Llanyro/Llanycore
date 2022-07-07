/*
 * ICountable.hpp
 *
 *  Created on: Sep 27, 2021
 *      Author: llanyro
 */

#ifndef CLASSCORE_ICOUNTABLE_HPP_
#define CLASSCORE_ICOUNTABLE_HPP_

#include "../headers/llanytypeslib.hpp"

namespace llcpp {
namespace classCore {

template<class T>
class ICountable {
	protected:
		T length;
	public:
		ICountable() { this->length = 0; }
		ICountable(const T& length) { this->length = length; }
		virtual ~ICountable() {}
		ICountable(const ICountable& other) { this->length = other.length; }
		ICountable(ICountable&& other) noexcept { this->length = other.length; }
		ICountable& operator=(const ICountable& other) {
			this->length = other.length;
			return *this;
		}
		ICountable& operator=(ICountable&& other) noexcept {
			this->length = other.length;
			return *this;
		}

		// Retorno: Numero de objetos en la lista
		// Complejidad temporal y espacial: O(1) y M(1)
		T count() const { return this->length; }
		T len() const { return this->length; }
		T size() const { return this->length; }
		virtual ll_bool_t clear() { this->length = 0; return true; }
		// Funcion: Comprueba si la posicion dada se puede encontrar en la lista
		// Version: Final
		// Precondiciones:
		//		Ninguna
		// Retorno:
		//		 true: position < length
		//		 false: position >= length
		// Complejidad temporal y espacial: O(1) y M(1)
		ll_bool_t inRange(const T& position) const { return position < this->length; }
};

} /* namespace classCore */
} /* namespace llcpp */

#endif /* CLASSCORE_ICOUNTABLE_HPP_ */
