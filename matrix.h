#include <iostream> 	// Allows input output operations
#include <iomanip>
#include <math.h>
#include <cstdio>

#define N           200
#define ARRAY_SIZE  (N*N)
#define M           100

using namespace std;

/*******************************************************************************
* Function Name  : determinant
* Description    : Given a square matrix array[][]. Calculates determinant.
*******************************************************************************/
float determinant(float array[N][N],float order);

/*******************************************************************************
* Function Name  : inverse
* Description    : Given a square matrix array[][]. Calculates inverse_array.
*******************************************************************************/


void inverse(float inv[N][N],float array[N][N],float order);


/*************************************************************
Function: multiply
Description: Matrix multiplication, First Matrix is the Product,
    second & Third are matrices to be multiplied,
    next 2 integers are row and columns of First Matrix
    Next 2 Integers are row and columns of second Matrix
******************************************************/

void multiply(float cipher[N][N],float array1[N][N],float array2[N][N], int order_1,int order_2,int marker_1,int marker_2);

