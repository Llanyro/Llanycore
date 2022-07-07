/*
 * memlib.hpp
 *
 *  Created on: Nov 16, 2020
 *      Author: llanyro
 */

#ifndef CORE_MEMLIB_HPP_
#define CORE_MEMLIB_HPP_

#include "../headers/llanytypeslib.hpp"

#define MEM_LIB llcpp::core::libs::mem

namespace llcpp {
namespace core {
namespace libs {
namespace mem {

	// Sets memory to zero memset()
void zeroMemory(void* data, s_bytes_t size_of);

// Realiza un calculo para devolver el puntero a la direccion de memoria deseada dentro de un bloque de memoria
// Es muy util cuando se usa algoritmos de void*
// Version: Beta
// Precondiciones:
//		mem_block != NULLPTR
//		posicion >= 0, size_of > 0
// Retorno: La direccion de memoria deseada
// Complejidad temporal y espacial: O(1) y M(1)
void* autoPointer(
	const void* mem_block, 		// Bloque de memoria donde se quiere realizar el AutoPointer
	ll_int64_t position,		// Posicion del bloque de emmoria a la que queremos castear
	s_bytes_t size_of);			// Bytes del tipo de cada elemento
/* Control de memoria */
// Funcion: Analiza un bloque de memoria dinamica para saber su tamanio
// Version: Final/Beta/Alfa/PreAlfa
// Precondiciones:
//		mem_block != NULLPTR
//		memblock is a dynamic vector
// Retorno: Void/Si se ha realizado todo correctamente
//		Resultado
// Complejidad temporal y espacial: O(1) y M(1)
len_t sizeof_(
		void* mem_block);				// Bloque a realocar(realloc)
// Cambia los datos de dos bloques de memoria usando un espacio de memoria auxiliar
// Precondiciones:
//		mem_block_a != NULLPTR && mem_block_b != NULLPTR
//		sizeBlock > 0 && size_of > 0
// Complejidad temporal y espacial: O(1) y M(n)
void swap(
	void* mem_block_a,			// Item o bloque 1
	void* mem_block_b,			// Item o bloque 2
	len_t size_block,			// Tamanio del bloque de memoria (Numero de items)
	s_bytes_t size_of);			// Bytes del tipo de cada elemento
ll_int8_t compareMemoryBlocks(
	const void* block1,			//
	len_t size_1,				//
	const void* block2,			//
	len_t size_2,				//
	s_bytes_t size_of,			//
	Compare_int compare);		//
/* Busquedas */
// Busca item dentro de un bloque de memoria
// Empieza a buscar desde: inicio hasta final
// Precondiciones:
//		mem_block != NULLPTR, item != NULLPTR
//		posInicial < posFinal, size_of > 0
// Retorno: Si ha encontrado el elemento (True)
// Complejidad temporal y espacial: O(posFinal - posInicial) y M(1)
ll_bool_t buscarObjeto(
	const void* mem_block,			// Bloque de datos a analizar
	len_t inicio,					// Posicion inicial al analizar (Incluida)
	len_t fin,						// Posicion final a analizar
	s_bytes_t size_of,				// Tamanio en bytes del tipo a analizar
	const void* item,				// Item a comparar
	Compare_bool compare);			// Funcion de comparacion de items (Recuerda que debe de devolver [1,0,-1])
// Busca item dentro de un bloque de memoria
// Empieza a buscar desde: final hasta inicio
// Precondiciones:
//		mem_block != NULLPTR, item != NULLPTR
//		posInicial < posFinal, size_of > 0
// Retorno: Si ha encontrado el elemento (True)
// Complejidad temporal y espacial: O(posFinal - posInicial) y M(1)
ll_bool_t buscarObjetoInvertido(
	// Bloque de datos a analizar
	const void* mem_block,
	// Posicion inicial al analizar (Incluida)
	len_t inicio,
	// Posicion final a analizar
	len_t fin,
	// Tamanio en bytes del tipo a analizar
	s_bytes_t size_of,
	// Item a comparar
	const void* item,
	// Funcion de comparacion de items (Recuerda que debe de devolver [1,0,-1])
	Compare_bool compare);
// Busca item dentro de un bloque de memoria (El menor)
// Empieza a buscar desde: inicio hasta final
// Precondiciones:
//		mem_block != NULLPTR
//		posInicial < posFinal, size_of > 0
// Retorno: Posicion del item menor(Si hay varios devuelve el ultimo)
// Complejidad temporal y espacial: O(sizeBlock - posInicial) y M(1)
len_t buscarPosicionObjetoMenor(
	// Bloque de datos a analizar
	const void* mem_block,
	// Posicion inicial al analizar (Incluida)
	len_t inicio,
	// Posicion final a analizar
	len_t fin,
	// Tamanio en bytes del tipo a analizar
	s_bytes_t size_of,
	// Funcion de comparacion de items (Recuerda que debe de devolver [1,0,-1])
	Compare_int compare);
/* Movimientos de memoria */
// Esta funcion es una version de "MemMove" que rellena los huecos vacios despues de mover datos
// Mueve datos de un bloque de memoria de posicion
// Usa la funcion "CopiarMemoria" y no "swap" para mover datos
// El signo de "unidadesDesplazar" selecciona la direccion donde se van a mover los items (+ ->) (- <-)
// Precondiciones:
//		mem_block != NULLPTR, NULLPTRValue != NULLPTR
//		posInicial >= 0, posFinal >= 0, size_of > 0
//		posInicial < posFinal
//		unidadesDesplazar != 0
//		size_of > 0
// Complejidad temporal y espacial: O(posFinal - posInicial + abs(unidadesDesplazar)) y M(1)
void memMoveExtra(
	// Bloque de memoria donde se quiere realizar el movimiento
	void* mem_block,
	// Posicion inicial del comienzo del movimiento(Posicion incluida)
	len_t inicio,
	// Posicion final del movimiento
	len_t fin,
	// Tamanio en bytes del tipo de la memoria
	s_bytes_t size_of,
	// Posiciones a desplazar y que direccion
	len_t unidadesDesplazar,
	// Si es en sentido positivo
	ll_bool_t adelante,
	// Objeto NULLPTR del tipo guardado para rellenar los huecos
	const void* nullValue);
// Mueve datos de un bloque de memoria de posicion
// Usa la funcion "CopiarMemoria" y no "swap" para mover datos
// El signo de "unidadesDesplazar" selecciona la direccion donde se van a mover los items
// Precondiciones:
//		mem_block != NULLPTR
//		posInicial >= 0, posFinal >= 0, size_of > 0
//		posInicial < posFinal
//		unidadesDesplazar != 0
// Complejidad temporal y espacial: O(posFinal - posInicial) y M(1)
void memMove(
	void* mem_block,			// Bloque de memoria donde se quiere realizar el movimiento
	len_t inicio,				// Posicion inicial del comienzo del movimiento(Posicion incluida)
	len_t fin,					// Posicion final del movimiento
	s_bytes_t size_of,			// Tamanio en bytes del tipo de la memoria
	len_t unidadesDesplazar,	// Posiciones a desplazar y que direccion
	ll_bool_t adelante);		// Si es en sentido positivo
// Cambia la posicion de los items de un vector contiguo (0 -> sizeBlock - 1) , (1 -> sizeBlock - 2)...
// Usa la funcion "Swap" por lo que, salirse de memoria dara error
// Precondiciones:
//		mem_block != NULLPTR
//		sizeBlock >= 0, size_of > 0
// Complejidad temporal y espacial: O(sizeBlock/2) y M(size_of)
void invertirBloque(
	// Bloque de memoria donde se quiere realizar el movimiento
	void* mem_block,
	// Tamanio de bloque
	len_t sizeBlock,
	// Tamanio del tipo en bytes
	s_bytes_t size_of);
/* Memoria compartida */
// Funcion: Genera un puntero a una memoria compartida
// Extra: Solo funciona en unix
// Precondiciones:
//		bytes != 0
// Retorno: El puntero a la memoria compartida
// Complejidad temporal y espacial: O(1) y M(1)
void* reservarMemoriaCompartida(len_t bytes);
/* Templates */

} /* namespace mem */
} /* namespace libs */
} /* namespace core */
} /* namespace llcpp */

#endif /* CORE_MEMLIB_HPP_ */
