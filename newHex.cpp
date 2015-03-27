#include <iostream>
#include <stdio.h>
using namespace std;
int main()

{
    char a;
    char b; 
    char t;
    while ((a = getchar())!='\n')
    {
        b = getchar();
        t = (char) ((unsigned int)a*16+(unsigned int)b);
        cout << t;
    }
}
