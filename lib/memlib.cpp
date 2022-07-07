/*
 * memlib.c
 *
 *  Created on: Nov 16, 2020
 *      Author: llanyro
 */

#include "memlib.hpp"

#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <assert.h>
#endif

namespace llcpp {
namespace core {
namespace libs {
namespace mem {

void zeroMemory(void* data, s_bytes_t size_of) {
	memset(data, 0, size_of);
}
void* autoPointer(const void* mem_block, ll_int64_t position, s_bytes_t size_of) {
	assert(mem_block != NULLPTR);
	assert(size_of > 0);
	assert(position >= 0);
	return (void*)(((const char*)mem_block) + (size_of * position));
}
s_bytes_t sizeof_(void* memBlock) {
	assert(memBlock != NULLPTR);
	#ifdef _WIN32
	return _msize(memBlock);
	#elif __unix__
	return malloc_usable_size(memBlock);
	#endif // _WIN32
}
void swap(void* mem_block_a, void* mem_block_b, len_t size_block, s_bytes_t size_of) {
	assert(mem_block_a != NULLPTR);
	assert(mem_block_b != NULLPTR);
	assert(size_of > 0);
	assert(size_block > 0);

	//Reservamos el espacio en memoria que queremos mover y lo copiamos
	len_t full_size = size_block * size_of;
	void* memtemp = malloc(size_block * size_of);
	memcpy(memtemp, mem_block_a, full_size);
	//Realizamos el swap con memcpy
	memcpy(mem_block_a, mem_block_b, full_size);
	memcpy(mem_block_b, memtemp, full_size);

	//Libaremos la memoria reservada temporal
	free(memtemp);
}
ll_int8_t compareMemoryBlocks(
	const void* block1, len_t size_1,
	const void* block2, len_t size_2,
	s_bytes_t sizeType, Compare_int compare) {
	assert(compare != NULLPTR);
	ll_int8_t result = 0;
	if (block1 == NULLPTR && block2 == NULLPTR) result = 0;	// Iguales
	else if (block1 == NULLPTR) result = -1;				// Bloque 2 mayor
	else if (block2 == NULLPTR) result = 1;					// Bloque 1 mayor
	else if (size_1 > size_2) result = 1;					// Bloque 1 mayor
	else if (size_1 < size_2) result = -1;					// Bloque 2 mayor
	else {													// Mismo tamanio
		for (len_t i = 0; result == 0 && i < size_1; i++)
			result = compare(
				autoPointer(block1, i, sizeType),
				autoPointer(block2, i, sizeType));
	}
	return result;
}
ll_bool_t buscarObjeto(
	const void* mem_block,
	len_t inicio, len_t fin, s_bytes_t size_of,
	const void* item, Compare_bool compare) {
	assert(mem_block != NULLPTR);
	assert(item != NULLPTR);
	assert(compare != NULLPTR);
	assert(size_of > 0);
	assert(inicio >= 0);
	assert(fin >= 0);
	assert(fin > inicio);
	ll_bool_t result = FALSE;
	for (len_t i = inicio; i < fin && !result; i++)
		result = compare(autoPointer(mem_block, i, size_of), item);
	return result;
}
ll_bool_t buscarObjetoInvertido(
	const void* memBlock,
	len_t inicio, len_t fin, s_bytes_t size_of,
	const void* item, Compare_bool compare) {
	assert(memBlock != NULLPTR);
	assert(item != NULLPTR);
	assert(compare != NULLPTR);
	assert(size_of > 0);
	assert(inicio >= 0);
	assert(fin >= 0);
	assert(fin > inicio);
	ll_bool_t result = FALSE;
	for (len_t i = fin - 1; i > inicio && !result; i--)
		result = compare(autoPointer(memBlock, i, size_of), item);
	return result;
}
len_t buscarPosicionObjetoMenor(
	const void* memBlock,
	len_t inicio, len_t fin, s_bytes_t size_of,
	Compare_int compare) {
	assert(memBlock != NULLPTR);
	assert(compare != NULLPTR);
	assert(size_of > 0);
	assert(inicio >= 0);
	assert(fin >= 0);
	assert(fin > inicio);
	len_t posMenor = inicio;
	for (len_t i = inicio + 1; i < fin; i++)
		if (compare(
			autoPointer(memBlock, posMenor, size_of),
			autoPointer(memBlock, i, size_of)) == 1)
			posMenor = i;
	return posMenor;
}
void memMoveExtra(void* memBlock,
	len_t inicio, len_t fin, s_bytes_t size_of,
	len_t unidadesDesplazar, ll_bool_t adelante, const void* nullValue) {
	assert(memBlock != NULLPTR);
	assert(nullValue != NULLPTR);
	assert(inicio >= 0);
	assert(fin >= 0);
	assert(fin > inicio);
	assert(size_of > 0);
	memMove(memBlock, inicio, fin, size_of, unidadesDesplazar, adelante);
	if (adelante) {
		//O(unidadesDesplazar)
		for (len_t i = inicio; i < inicio + unidadesDesplazar; i++)
			memcpy(autoPointer(memBlock, i, size_of), nullValue, size_of);
	}
	else {
		//O(unidadesDesplazar)
		for (len_t i = fin - unidadesDesplazar; i < fin; i++)
			memcpy(autoPointer(memBlock, i, size_of), nullValue, size_of);
	}
}
void memMove(void* memBlock,
	len_t inicio, len_t fin, s_bytes_t size_of,
	len_t unidadesDesplazar, ll_bool_t adelante) {
	assert(memBlock != NULLPTR);
	assert(inicio >= 0);
	assert(fin >= 0);
	assert(fin > inicio);
	assert(size_of > 0);
	if (adelante) {
		//O(fin - inicio)
		for (len_t i = fin - 1; i > inicio; i--)
			memcpy(
				autoPointer(memBlock, i, size_of),
				autoPointer(memBlock, i - unidadesDesplazar, size_of), size_of);
	}
	else {
		//O(fin - inicio)
		for (len_t i = inicio; i < fin - 1; i++)
			memcpy(
				autoPointer(memBlock, i, size_of),
				autoPointer(memBlock, i + unidadesDesplazar, size_of), size_of);
	}
}
void invertirBloque(void* memBlock,
	len_t sizeBlock, s_bytes_t size_of) {
	assert(memBlock != NULLPTR);
	assert(size_of > 0);
	assert(sizeBlock > 0);
	for (len_t i = 0; i < (sizeBlock / 2); i++)
		swap(
			autoPointer(memBlock, i, size_of),
			autoPointer(memBlock, sizeBlock - 1 - i, size_of), 1, size_of);
}
/* Memoria compartida */
void* reservarMemoriaCompartida(len_t bytes) {
	assert(bytes > 0);
	void* memoria = NULLPTR;
	#ifdef _WIN32

	#elif __unix__
	//memoria = mmap(NULLPTR, bytes, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	#endif // _WIN32
	return memoria;
}


} /* namespace mem */
} /* namespace libs */
} /* namespace core */
} /* namespace llcpp */

