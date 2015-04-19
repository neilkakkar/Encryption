#include <iostream> 	// Allows input output operations
#include <iomanip>
#include <math.h>
#include <cstdio>

#include "matrix.h"

/*******************************************************************************
* Function Name  : array_map
* Description    : Maps plain_text_zero_padded to mapped_array using mapping array
*******************************************************************************/


void array_map(char mapped_array[ARRAY_SIZE], char plain_text_zero_padded[ARRAY_SIZE]);

/*******************************************************************************
* Function Name  : keygen
* Description    : Generates the Key file to be used for encryption
*******************************************************************************/

void keygen(float key[N][N], int marker);

