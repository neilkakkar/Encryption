#include "matrix.h"
/*******************************************************************************
* Function Name  : determinant
* Description    : Given a square matrix array[][]. Calculates determinant.
*******************************************************************************/
float determinant(float array[N][N],float order)
{
    if(order==1)
    {
        return array[0][0];
    }

    float ans=0;
    float array1[N][N];
    int itemp,jtemp;
    for(int c=0;c<order;c++)
    {

        itemp=0;
        for(int i=1;i<order;i++)
        {

            jtemp=0;
            for(int j=0;j<order;j++)
            {
                if(j==c)
                {
                    continue;
                }
                else
                {
                    array1[itemp][jtemp]=array[i][j];
                    jtemp++;
                }

            }
            itemp++;
        }
        if(c%2==0){
        ans+=array[0][c]*determinant(array1,order-1);
        }
        else{
        ans+=-1*array[0][c]*determinant(array1,order-1);
        }

    }
    return ans;

}

/*******************************************************************************
* Function Name  : inverse
* Description    : Given a square matrix array[][]. Calculates inverse_array.
*******************************************************************************/


void inverse(float inv[N][N],float array[N][N],float order)
{
    if(order==1)
    {
        inv[0][0]=1/array[0][0];
    }
    else
    {
        float temp[N][N];
        float det = determinant(array,order);
        for(int i=0;i<order;i++)
        {
            for(int j=0;j<order;j++)
            {
                int rtemp,ktemp;
                rtemp=0;
                for(int r=0;r<order;r++)
                {
                    if(r==i)
                    {
                        continue;
                    }
                    else
                    {
                        ktemp=0;
                        for(int k=0;k<order;k++)
                        {
                            if(k==j)
                            {
                                continue;
                            }
                            else
                            {
                                temp[rtemp][ktemp]=array[r][k];
                                ktemp++;
                            }
                        }
                    }
                    rtemp++;
                }

                inv[j][i] = (pow(-1,i+j)*determinant(temp,order-1))/det;
            }
        }
    }

}



/*************************************************************

Function: multiply
Description: Matrix multiplication, First Matrix is the Product,
    second & Third are matrices to be multiplied,
    next 2 integers are row and columns of First Matrix
    Next 2 Integers are row and columns of second Matrix
******************************************************/

void multiply(float cipher[N][N],float array1[N][N],float array2[N][N], int order_1,int order_2,int marker_1,int marker_2)
{
    if(order_2!=marker_1)
    {
        cout<<"Multiplication Error, Size mismatch\n";
    }
    else
    {
        for(int i=0;i<order_1;i++)
        {
            for(int j=0;j<order_2;j++)
            {
                cipher[i][j]=0;
                for(int k=0;k<order_2;k++)
                {
                    cipher[i][j]+=array1[i][k]*array2[k][j];
                }
            }
        }
    }
}

