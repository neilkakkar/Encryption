#include "encryption.h"
#include "map.h"

void array_map(char mapped_array[ARRAY_SIZE], char plain_text_zero_padded[ARRAY_SIZE])
{
    for(int i=0;i<ARRAY_SIZE;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(map[j][0]==plain_text_zero_padded[i])
            {
                mapped_array[i] = map[j][1];
                break;
            }
        }
    }
}


void keygen(float key[N][N], int marker)
{
  int i,j;

 for(i=0;i<marker;i++){
    for(j=0;j<marker;j++){
      if(i != j)
        key[i][j] = marker;
      else
        key[i][j] = marker + 1;
    }
  }

};


int main()
{
    char plain_text[ARRAY_SIZE];
    int marker;

    float key[N][N];

    float cipher_text[N][N];

    /***************Get User Input***************/


    cout << "Enter the plain text" << endl;
    cin >> plain_text;

    cout << "Enter the marker" << endl;
    cin >> marker;

    // Creating a key matrix of size (marker x marker)
    keygen(key,marker);


    /***************End User Input***************/


	int length_of_input;
    for (length_of_input = 0;plain_text[length_of_input];length_of_input++); //Get length of input


    char input_padded[ARRAY_SIZE];
    for(int i=0;i<length_of_input;i++)
    {
        input_padded[i] = plain_text[i];
    }

    int temp;
    if(length_of_input%marker!=0)
    {
        temp = marker - length_of_input%marker;
        for(int i=length_of_input;i<length_of_input+temp;i++)
        {
            input_padded[i]='0';
        }
        length_of_input+=temp;

    }

    char Mapped_Array[ARRAY_SIZE];

    array_map(Mapped_Array,input_padded);

    float Dimensional_Mapped_array[N][N];

    int index=0;
    for(int i=0;i<length_of_input/marker;i++)
    {
        for(int j=0;j<marker;j++)
        {
            Dimensional_Mapped_array[i][j] = Mapped_Array[index];
            index++;
        }
    }

    multiply(cipher_text,Dimensional_Mapped_array,key,length_of_input/marker,marker,marker,marker);


    /*for(int i=0;i<length_of_input/marker;i++)//To take care of floating point errors!
    {
        for(int j=0;j<marker;j++)
        {
            if(cipher_text[i][j]-floor(cipher_text[i][j])>0.5)
            {
                cipher_text[i][j]=ceil(cipher_text[i][j]);
            }
            else
            {
                cipher_text[i][j] = floor(cipher_text[i][j]);
                //cout<<(char)floor(cipher_text[i][j]);
            }
        }

    }*/

    float Cipher[ARRAY_SIZE];
    index=0;
    for(int i=0;i<length_of_input/marker;i++)
    {
        for(int j=0;j<marker;j++)
        {
            Cipher[index] = cipher_text[i][j] ;
            index++;
        }
    }

    freopen("ciphertext.txt","w",stdout);
    cout<<index<<endl;
    for(int i=0;i<index;i++)
    {
        cout<<Cipher[i]<<" ";
    }
    return 0;
}
