#include <iostream>
#include <stdio.h>

#define min(X,Y) X<Y?X:Y
using namespace std;
int main()
{
    printf ("Trying to decrypt data\n");
    printf("Give the string to read\n");
    unsigned int data[11][1000];
    int datalen[11] = {0};
    char  a[1000];
    unsigned int key[1000] = {0};
    char * b = a;
    for (int j = 0 ; j < 1 ; j++)
    {
        printf("\n\nThese are datas\n***\n");
        b = a;
        int i = 0;
        while (*(b-1) != '\n')
        {
            (*b++)  = getchar();
            if ( *(b-1)  == '\n' ) break;
            (*b++)  = getchar();
            sscanf((b-2),"%2x",&data[j][i]);
            printf("%c",(char)data[j][i]);
            i++;
        }
        datalen[j] = i;
    }
    cout << a;
  /*  for (int i=0; i < datalen[0];i++)
    {
        data[2][i] = data[1][i] ^ data[0][i];
        cout << data[2][i];
    }*/
/*
    char *cha2 ="ABCDEFGHIJKLMANOPQRSTUVWXYZ";
    char *spa = "                           ";
    char *cha = "abcdefghijklmanopqrstuvwxyz";
    for (int i = 0 ; i<27;i++)
    {
        printf ("%d %d %d\n", spa[i], cha[i],(spa[i]^cha[i]));
        printf ("%d %d %d\n", spa[i], cha2[i],(spa[i]^cha2[i]));
    }
    unsigned int dataXor[10][10][1000];
    int keypossible[10][1000] = {0};
    for (int m=2;m<10;m++)
    {
        for (int n=0; n < 10; n++)
        {
            printf("%d %d ",m ,n);
            printf("%d %d %d \n",datalen[m],datalen[n], min(datalen[m],datalen[n]));
            int minlen = min(datalen[m],datalen[n]);
            //for (int j=0;j< min(datalen[m],datalen[n]);j++) 
            for (int j=0;j< minlen;j++)
            {
                dataXor[m][n][j] = (data[m][j]^data[n][j]);
            }
        }
    } 
    int temp =min(datalen[0],datalen[1]);
    for (int j=0;j<temp;j++) 
    {
        printf("%u\n",dataXor[3][1][j]);
    }
    for (int m=0;m<10;m++)
    {
        for (int n=0; n < 10; n++)
        {
            printf("%d %d ",m ,n);
            printf("%d %d %d \n",datalen[m],datalen[n], min(datalen[m],datalen[n]));
            int minlen = min(datalen[m],datalen[n]);
            //for (int j=0;j< min(datalen[m],datalen[n]);j++) 
            for (int j=0;j< minlen;j++)
            {
                if (dataXor[m][n][j] >=64 && dataXor[m][n][j]  < 128)// && (dataXor[m][n][j+1] <=64 || dataXor[m][n][j+1] > 128))
                {
                   keypossible[m][j]++;     
                }
            }
        }
    }
    for (int m =1;m<10;m++)
    {
        for (int j=0;j<datalen[10];j++)
        {
            if (keypossible[m][j] > 3)
            {
                key[j] = data[m][j]^32;
            }
        }
    }
    char result[150];
    for (int j=0;j<datalen[10];j++)
    {
         result[j] = (char)data[10][j]^key[j];
         cout << result[j];
        // cout << key[j]<< " ";
    }
*/
}
