/*
Author : Avia Avikasis
Reviewer : Aharon Cohen
3/06/2022
*/

#include "bit_array.h"

#define SIXTY_FOUR_BITS 64
#define MAX_SIZE_OF_8B 0xffffffffffffffff
#define TWO_POW64      0x8000000000000000

static const char digits[2] = "01";

/* REVERSE_BIT insert in each index the mirror value of index */
#define R2(n) n, n + 2*64, n + 1*64, n + 3*64
#define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16)
#define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )
#define REVERSE_BITS R6(0), R6(2), R6(1), R6(3)

/* COUNT_BITS insert in each index the num that need to represent the value of index */
#define B2(n) n, n + 1, n + 1, n + 2
#define B4(n) B2(n), B2(n + 1), B2(n + 1), B2(n + 2)
#define B6(n) B4(n), B4(n + 1), B4(n + 1), B4(n + 2)
#define COUNT_BITS B6(0), B6(1), B6(1), B6(2)



const bit_array_ty lut_arr_mirror[256] = {REVERSE_BITS};
const bit_array_ty lut_arr_counton[256] = {COUNT_BITS};

size_t Log2n(size_t n);


bit_array_ty BitArraySetAll()
{
	return MAX_SIZE_OF_8B;
} 


bit_array_ty BitArrayResetAll()
{
	return 0;
} 


bit_array_ty BitArrayMirror(bit_array_ty bit_arr)
{
  	bit_arr = (((bit_arr & 0xaaaaaaaaaaaaaaaa) >> 1) | ((bit_arr & 0x5555555555555555) << 1));
    bit_arr = (((bit_arr & 0xcccccccccccccccc) >> 2) | ((bit_arr & 0x3333333333333333) << 2));
    bit_arr = (((bit_arr & 0xf0f0f0f0f0f0f0f0) >> 4) | ((bit_arr & 0x0f0f0f0f0f0f0f0f) << 4));
    bit_arr = (((bit_arr & 0xff00ff00ff00ff00) >> 8) | ((bit_arr & 0x00ff00ff00ff00ff) << 8));
    bit_arr = (((bit_arr & 0xffff0000ffff0000) >> 16) | ((bit_arr & 0x0000ffff0000ffff) << 16));
    bit_arr = (((bit_arr & 0xffffffff00000000) >> 32) | ((bit_arr & 0x00000000ffffffff) << 32));

    return bit_arr;
}



size_t BitArrayCountOff(bit_array_ty bit_arr)
{

	return  BitArrayCountOn(~bit_arr);

}


int BitArrayGetValue(bit_array_ty bit_arr, size_t index)
{
	return ((bit_arr >> index) & 1 );
}


bit_array_ty BitArrayFlip(bit_array_ty bit_arr)
{
	return ~bit_arr;
}


char * BitArrayToString(bit_array_ty bit_arr, char *dest)
{
	unsigned int len = 0;
	len += Log2n(bit_arr) + 1;                                                    
	dest[len] = '\0'; 
	                                    
	for ( ; len > 0 ; --len)
	{
		dest[len-1] = digits[bit_arr % 2];
		bit_arr /= 2;
	}
	
	return dest;
}


bit_array_ty BitArraySetOn(bit_array_ty bit_arr, size_t index)
{
	return (bit_arr | 1ul << index);
}


bit_array_ty BitArraySetOff(bit_array_ty bit_arr, size_t index)
{
	return ( ~(~bit_arr | 1ul << index) );
}



bit_array_ty BitArraySetBit(bit_array_ty bit_arr, size_t index, size_t bit_value)
{
	if( (((bit_value << index) ^ bit_arr) & 1ul << index ) ==  1ul << index)  /* if bit_value & index value are difference */
	{
		return (bit_arr ^ (1ul << index));
	}
	
	return bit_arr;
			
}


size_t BitArrayCountOn(bit_array_ty bit_arr)
{
	bit_arr = ((bit_arr & 0x5555555555555555) + ((bit_arr >> 1) & 0x5555555555555555));
    bit_arr = ((bit_arr & 0x3333333333333333) + ((bit_arr >> 2) & 0x3333333333333333));
    bit_arr = ((bit_arr & 0x0f0f0f0f0f0f0f0f) + ((bit_arr >> 4) & 0x0f0f0f0f0f0f0f0f));
    bit_arr = ((bit_arr & 0x00ff00ff00ff00ff) + ((bit_arr >> 8) & 0x00ff00ff00ff00ff));
    bit_arr = ((bit_arr & 0x0000ffff0000ffff) + ((bit_arr >> 16) & 0x0000ffff0000ffff));
    bit_arr = ((bit_arr & 0x00000000ffffffff) + ((bit_arr >> 32) & 0x00000000ffffffff));

    return bit_arr;

}


bit_array_ty BitArrayRotateLeft(bit_array_ty bit_arr, size_t rotation_amount)
{
		
	return (bit_arr << (rotation_amount % SIXTY_FOUR_BITS) | 
	bit_arr >> (SIXTY_FOUR_BITS - rotation_amount % SIXTY_FOUR_BITS));

}


bit_array_ty BitArrayRotateRight(bit_array_ty bit_arr, size_t rotation_amount)
{
		
	return (bit_arr >> (rotation_amount % SIXTY_FOUR_BITS) | 
	bit_arr << (SIXTY_FOUR_BITS - rotation_amount % SIXTY_FOUR_BITS));

}


bit_array_ty BitArrayLutMirror(bit_array_ty bit_arr)
{
	
	return (lut_arr_mirror[bit_arr & 0xff] << 56   | 
		lut_arr_mirror[bit_arr >> 8 & 0xff] << 48  |
		lut_arr_mirror[bit_arr >> 16 & 0xff] << 40 |
		lut_arr_mirror[bit_arr >> 24 & 0xff] << 32 |
		lut_arr_mirror[bit_arr >> 32 & 0xff] << 24 |
		lut_arr_mirror[bit_arr >> 40 & 0xff] << 16 |
		lut_arr_mirror[bit_arr >> 48 & 0xff] << 8  |
		lut_arr_mirror[bit_arr >> 56 & 0xff] );	
}


size_t BitArrayLutCountOn(bit_array_ty bit_arr)
{
	
	return ( (lut_arr_counton[bit_arr & 0xff] ) + 
		(lut_arr_counton[bit_arr >> 8 & 0xff] ) +
		(lut_arr_counton[bit_arr >> 16 & 0xff]) +
		(lut_arr_counton[bit_arr >> 24 & 0xff]) +
		(lut_arr_counton[bit_arr >> 32 & 0xff]) +
		(lut_arr_counton[bit_arr >> 40 & 0xff]) +
		(lut_arr_counton[bit_arr >> 48 & 0xff]) +
		(lut_arr_counton[bit_arr >> 56 & 0xff]) );
}


size_t Log2n(size_t n)
{
    return (n > 1) ? 1 + Log2n(n / 2) : 0;
}


























