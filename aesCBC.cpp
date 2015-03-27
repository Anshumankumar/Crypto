#include <iostream>
#include <stdio.h>
#include <openssl/aes.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//#include "Crypto++/aes.h"
using namespace std;

int main()
{
    cout <<"Implementing CBC Aes encryption and Decryption Algos" << endl;
    unsigned int key[16];
    unsigned char ckey[16];
    unsigned int cipertext[100];
    unsigned char ciper[100];
    unsigned int message[100];
    unsigned char mess[100];
    unsigned int iv[16];
    unsigned char civ[16];

    char b[2];
    int i = 0;
    while ((*(b+1)) != '\n')
    {
        (*b) = getchar();
        if ((*b) == '\n') break;
        *(b+1) = getchar();
        sscanf(b,"%2x",&key[i]);
        ckey[i] = key[i];
        i++;
    }
    i = 0;
    while ((*(b+1)) != '\n')
    {
        (*b) = getchar();
        if ((*b) == '\n') break;
        *(b+1) = getchar();
        sscanf(b,"%2x",&cipertext[i]);
        ciper[i] = cipertext[i];
        i++;
    }
    int cipertextlen = i;
    i =0;
    
    AES_KEY dec_key;
    AES_set_encrypt_key(ckey, 128, &dec_key);
    unsigned char ucounter[16];
    memset(ucounter,16,0);
    unsigned int num = 0;
    unsigned char counter[16];
    memcpy(counter,ciper,16);
    AES_ctr128_encrypt(&ciper[16], mess, cipertextlen-16, &dec_key,counter,ucounter,&num);
    for (i =0; i<16;i++)
    {
        cout << (unsigned char)key[i];
    }
     cout << endl;
     
    for(i =0;i<cipertextlen-16;i++)
    {
        cout <<(char)mess[i];
    }
    return 0;
}
