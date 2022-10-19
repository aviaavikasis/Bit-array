#ifndef __ILRD_OL127_128_BITARRAY_H__
#define __ILRD_OL127_128_BITARRAY_H__

#include <stddef.h>


typedef size_t bit_array_ty;


bit_array_ty BitArraySetAll();
 

bit_array_ty BitArrayResetAll();


bit_array_ty BitArraySetOn(bit_array_ty bit_arr, size_t index);

                    
bit_array_ty BitArraySetOff(bit_array_ty bit_arr, size_t index);


int BitArrayGetValue(bit_array_ty bit_arr, size_t index);


bit_array_ty BitArraySetBit(bit_array_ty bit_arr, size_t index, size_t bit_value);


bit_array_ty BitArrayFlip(bit_array_ty bit_arr);


bit_array_ty BitArrayMirror(bit_array_ty bit_arr);


size_t BitArrayCountOn(bit_array_ty bit_arr);


size_t BitArrayCountOff(bit_array_ty bit_arr);


bit_array_ty BitArrayRotateLeft(bit_array_ty bit_arr, size_t rotation_amount);


bit_array_ty BitArrayRotateRight(bit_array_ty bit_arr, size_t rotation_amount);


char * BitArrayToString(bit_array_ty bit_arr, char *dest);

bit_array_ty BitArrayLutMirror(bit_array_ty bit_arr);

size_t BitArrayLutCountOn(bit_array_ty bit_arr);


#endif /* __ILRD_OL127_128_BITARRAY_H__ */
