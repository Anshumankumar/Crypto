#include <iostream>
#include <fstream>
#include <openssl/sha.h>
using namespace std;
int main(int argc, char ** argv)
{
    cout << "This file take will calculate the file sha\n";
    if (argc < 2)
    {
        cout << "Invlaid syntax\n";
        cout << "Usage: filesha filename\n";
        return -1;
    }
    char *data;
    unsigned char hash[32];
    int size;
    ifstream file (argv[1],ios::in|ios::binary|ios::ate);
    if (file.is_open())
    {
        size = file.tellg();
        data = new char[size];
        file.seekg(0,ios::beg);
        file.read(data, size);
        file.close();
        int blocknum = size/1024 + 1;
        int lastblock = size%1024;
        int currentpointer  = size-lastblock;
        SHA256((unsigned char*)&data[currentpointer],lastblock,hash);
        for (int i = blocknum-2 ; i >= 0; i--)
        {
            unsigned char tempblock [1056];
            for (int j =0; j < 1024;j++)
            {
                tempblock[j] = (unsigned char)data[i*1024+j];
            }
            for (int j =1024; j < 1056;j++)
            {
                tempblock[j] = (unsigned char)hash[j-1024];
            }

            SHA256((unsigned char*)tempblock,1056,hash);
        }

        for(int i = 0; i < 32; ++i) 
        {
            if ((int)hash[i] < 16) cout << "0";
            cout <<hex<< (int)hash[i];
        }
        delete[] data;
    }
    else 
    {
        cout << "Unable to open file";
    }
}
