#include "decryption.h"
#include "map.h"

void inv_array_map(char inv_mapped_array[ARRAY_SIZE], char decrypt_plain_text_zero_padded[ARRAY_SIZE])
{
    for(int i=0;i<ARRAY_SIZE;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(inv_mapped_array[i] == map[j][1])
            {
                decrypt_plain_text_zero_padded[i] = map[j][0];
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

}

int main()
{
    float invkey[N][N];
    float key[N][N];
    char decrypt_plain_text[ARRAY_SIZE];
    float encrypted_text[ARRAY_SIZE];


    int marker;
    cout<<"Please enter the marker used to encrypt the text\n";
    cin>>marker;

    cout<<"Please place the text to be decrypted in the file ciphertext.txt in the current folder\n";

    freopen("ciphertext.txt","r",stdin);
    int length_of_input;
    //cout<<"Please enter the length of input\n";
    cin>>length_of_input;

    //cout<<"Please enter the encrypted text\n";

    for(int i=0;i<length_of_input;i++)
    {
        cin>>encrypted_text[i];
    }

    //if(length_of_input%marker!=0)
    //{
    //    cout<<"The cipher text has become corrupt. Exiting...\n";
    //    return 0;
    //}

    keygen(key,marker);
    inverse(invkey,key,marker);


    float cipher_text[N][N];

    int index=0;
    for(int i=0;i<length_of_input/marker;i++)
    {
        for(int j=0;j<marker;j++)
        {
            cipher_text[i][j] = encrypted_text[index];
            index++;
        }
    }

    float B[N][N]; // The Decrypted matrix;



    multiply(B,cipher_text,invkey,length_of_input/marker,marker,marker,marker);

    char B_linear[ARRAY_SIZE];

    for(int i=0;i<length_of_input/marker;i++)//To take care of floating point errors!
    {
        for(int j=0;j<marker;j++)
        {
            if(B[i][j]-floor(B[i][j])>0.5)
            {
                B[i][j]=ceil(B[i][j]);
            }
            else
            {
                B[i][j] = floor(B[i][j]);
                //cout<<(char)floor(B[i][j]);
            }
        }

    }
    index=0;
    for(int i=0;i<length_of_input/marker;i++)
    {
        for(int j=0;j<marker;j++)
        {
            B_linear[index] = (char)B[i][j];
            index++;
        }
    }

    inv_array_map(B_linear,decrypt_plain_text);

    cout<<decrypt_plain_text;
}
