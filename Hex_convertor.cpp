#include <stdio.h>
using namespace std;
int main()
{
char a[] = "attack at dawn";
char b[] = "attack at dusk";
int  c[] = { 0x6c,0x73,0xd5,0x24,0x0a,0x94,0x8c,0x86,0x98,0x1b,0xc2,0x94,0x81,0x4d }; 
for (int i = 0 ; i < 14; i++)
{
        printf("%x",(a[i] ^ b[i] ^ c[i])%256) ;
}
return 0;

}
