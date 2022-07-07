/*
 * LlanyCore.hpp
 *
 *  Created on: Sep 27, 2021
 *      Author: llanyro
 */

#ifndef CLASSCORE_LLANYCORE_HPP_
#define CLASSCORE_LLANYCORE_HPP_

#include "../headers/llanytypeslib.hpp"

#define CLASS_CORE llcpp::classCore

namespace llcpp {

namespace hashlib {
namespace hash {
class Hash;
}
}

namespace classCore {
class String;

class ILlanyCore {
	public:
		virtual ~ILlanyCore() {}
		// Funcion: Limpia el objeto
		// Devuelve true si todo ha salido correctamente
		// Complejidad temporal y espacial: O(?) y M(1)
		virtual ll_bool_t clear() = 0;
		// Devuelve un hash del objeto en formato Hash
		virtual hashlib::hash::Hash* hash() const = 0;
		// Sirve para generar una funcion para poder printear la clase
		virtual String* toString() const = 0;
		// Serialize y toJSON son iguales, es decir
		//	el serializador simula o imita el metodo json
		virtual String* serialize() const = 0;
		virtual void* clone() const = 0;
};

} /* namespace classCore */
} /* namespace llcpp */

#endif /* CLASSCORE_LLANYCORE_HPP_ */
