/*
 * charslib.h
 *
 *  Created on: Mar 16, 2022
 *      Author: llanyro
 */

#ifndef CORE_CHARSLIB_HPP_
#define CORE_CHARSLIB_HPP_

#include "../headers/llanytypeslib.hpp"

#define CHARS_LIB llcpp::core::libs::chars

namespace llcpp {
namespace core {
namespace libs {
namespace chars {

ll_int_t compareCharSimilar(const void* caracter1, const void* caracter2);
ll_int_t compareChar(const void* caracter1, const void* caracter2);

// Funcion: Comprueba si dos caracteres son similares
// Version: Final
// Precondiciones:
//		caracter1 != nullptr
//		caracter2 != nullptr
// Retorno:
//		-3 = Error
//		-2 = Error
//		-1 = caracter1 es menor a caracter2
//		 1 = caracter1 es mayor a caracter2
//		 0 = Ambos son iguales o similares(mayus-minus/minus-mayus)
// Complejidad temporal y espacial: O(1) y M(1)
ll_int_t compareCharSimilar(const char* caracter1, const char* caracter2);
ll_bool_t similarChar(const char* caracter1, const char* caracter2);
// Funcion: Comprueba si dos caracteres son iguales
// Version: Final
// Precondiciones:
//		caracter1 != nullptr
//		caracter2 != nullptr
// Retorno:
//		-2 = Error
//		-1 = caracter1 es menor a caracter2
//		 1 = caracter1 es mayor a caracter2
//		 0 = Ambos son iguales
// Complejidad temporal y espacial: O(1) y M(1)
ll_int_t compareChar(const char* caracter1, const char* caracter2);
// Funcion: Coemprueba si un caracter es del alfabeto o no
// Version: Final
// Precondiciones:
//		caracter != nullptr
// Retorno:
//		 0 = No es del alfabeto
//		 1 = Es una mayuscula
//		-1 = Es una minuscula
// Complejidad temporal y espacial: O(1) y M(1)
ll_int_t isAlphabet(const char* caracter);
// Funcion: Cambia un caracter a mayusculas si es minuscula
// Version: Final
// Precondiciones:
//		caracter != nullptr
// Retorno:
//		 0 = No es del alfabeto
//		 1 = Se ha cambiado a mayus
//		-1 = Ya era mayus
// Complejidad temporal y espacial: O(1) y M(1)
ll_int_t cambiarMayus(char* caracter);
// Funcion: Cambia un caracter a minuscula si es mayuscula
// Version: Final
// Precondiciones:
//		caracter != nullptr
// Retorno:
//		 0 = No es del alfabeto
//		 1 = Se ha cambiado a minuscula
//		-1 = Ya era minuscula
// Complejidad temporal y espacial: O(1) y M(1)
ll_int_t cambiarMinus(char* caracter);

} /* namespace chars */
} /* namespace libs */
} /* namespace core */
} /* namespace llcpp */

#endif /* CORE_CHARSLIB_HPP_ */
