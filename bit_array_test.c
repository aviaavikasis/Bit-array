#include "bit_array.h"
#include <stdio.h>   /* printf */
#include <stdlib.h>  /* malloc */

#define TWO_POW64      0x8000000000000000

void PrintNumInBinary(bit_array_ty num);

int main()
{

	char *dest = (char*)malloc(65);
	bit_array_ty bit_arr = 6147152;  	
	
/*-------------test of BitArraySetAll function--------*/	
	
	printf("--------------test of BitArraySetAll function-------------\n\n");
	printf("the source number : \n");
	PrintNumInBinary(bit_arr);
	printf("the return number : \n");
	PrintNumInBinary(BitArraySetAll(bit_arr));
	printf("\n\n\n");
	
	
/*-------------test of BitArrayResetAll function--------*/	
    
    printf("--------------test of BitArrayResetAll function-------------\n\n");
	printf("the source number : \n");
	PrintNumInBinary(bit_arr);
	printf("the return number : \n");
	PrintNumInBinary(BitArrayResetAll(bit_arr));
	printf("\n\n\n");


/*-------------test of BitArraySetOn function--------*/	

    printf("--------------test of BitArraySetOn function-------------\n\n");
	printf("the source number : \n");
	PrintNumInBinary(bit_arr);
	printf("the return number for index 50: \n");
	PrintNumInBinary(BitArraySetOn(bit_arr , 50));
	printf("\n\n\n");


/*-------------test of BitArraySetOff function------*/	

  	printf("--------------test of BitArraySetOff function-------------\n\n");
	printf("the source number : \n");
	PrintNumInBinary(bit_arr);
	printf("the return number for index 4: \n");
	PrintNumInBinary(BitArraySetOff(bit_arr , 4));
	printf("\n\n\n");


/*-------------test of BitArrayGetValue function------  */	

	printf("--------------test of BitArrayGetValue function-------------\n\n");
	printf("the source number : \n");
	PrintNumInBinary(bit_arr);
	printf("the return number for index 4: \n");
	PrintNumInBinary(BitArrayGetValue(bit_arr , 4));
	printf("\n\n\n");


/*-------------test of BitArraySetBit function------*/	


	printf("--------------test of BitArraySetBit function-------------\n\n");
	printf("the source number : \n");
	PrintNumInBinary(bit_arr);
	printf("the return number : \n");
	PrintNumInBinary(BitArraySetBit(bit_arr , 4 , 0));
	printf("\n\n\n");



/*-------------test of BitArrayFlip function------*/	


	printf("--------------test of BitArrayFlip function-------------\n\n");
	printf("the source number : \n");
	PrintNumInBinary(bit_arr);
	printf("the return number : \n");
	PrintNumInBinary(BitArrayFlip(bit_arr));
	printf("\n\n\n");


/*-------------test of BitArrayMirror function------*/	


	printf("--------------test of BitArrayMirror function-------------\n\n");
	printf("the source number : \n");
	PrintNumInBinary(bit_arr);
	printf("the return number : \n");
	PrintNumInBinary(BitArrayMirror(bit_arr));
	printf("\n\n\n");

/*-------------test of BitArrayCountOn function------*/	


	printf("--------------test of BitArrayCountOn function-------------\n\n");
	printf("the source number : \n");
	PrintNumInBinary(bit_arr);
	printf("the return number : \n");
	PrintNumInBinary(BitArrayCountOn(bit_arr));
	printf("\n\n\n");

/*-------------test of BitArrayCountOff function------*/	


	printf("--------------test of BitArrayCountOff function-------------\n\n");
	printf("the source number : \n");
	PrintNumInBinary(bit_arr);
	printf("the return number : \n");
	PrintNumInBinary(BitArrayCountOff(bit_arr));
	printf("\n\n\n");


/*-------------test of BitArrayRotateLeft function------*/	

	printf("--------------test of BitArrayRotateLeft function-------------\n\n");
	printf("the source number : \n");
	PrintNumInBinary(bit_arr);
	printf("the return number for 66 rotates: \n");
	PrintNumInBinary(BitArrayRotateLeft(bit_arr , 66));
	printf("\n\n\n");


/*-------------test of BitArrayRotateRight function------*/	

	printf("--------------test of BitArrayRotateRight function-------------\n\n");
	printf("the source number : \n");
	PrintNumInBinary(bit_arr);
	printf("the return number for 69 rotates: \n");
	PrintNumInBinary(BitArrayRotateRight(bit_arr , 69));
	printf("\n\n\n");


/*-------------test of BitArrayToString function------*/	
	
	printf("--------------test of BitArrayToString function-------------\n\n");
	printf("the source number : \n");
	PrintNumInBinary(bit_arr);
	printf("the return number : \n");
	printf("%s\n\n" , BitArrayToString(bit_arr , dest));
	
	
/*-------------test of BitArrayLutMirror function------*/	


	printf("--------------test of BitArrayLutMirror function-------------\n\n");
	printf("the source number : \n");
	PrintNumInBinary(bit_arr);
	printf("the return number : \n");
	PrintNumInBinary(BitArrayLutMirror(bit_arr));
	printf("\n\n\n");
	
	
	
/*-------------test of BitArrayLutCountOn function------*/	


	printf("--------------test of BitArrayLutCountOn function-------------\n\n");
	printf("the source number : \n");
	PrintNumInBinary(bit_arr);
	printf("the return number : \n");
	PrintNumInBinary(BitArrayLutCountOn(bit_arr));
	printf("\n\n\n");
	
	free(dest);
	
	
	return 0;


}



void PrintNumInBinary(bit_array_ty num)
{
	bit_array_ty test = TWO_POW64;
	while(0 != test)
	{
		printf("%d " ,(0 != (num & test)));
		test >>= 1;
	}
	printf("\n\n");
}
