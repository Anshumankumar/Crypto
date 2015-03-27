#include <iostream>
using namespace std;
int main()
{
    unsigned char a = (unsigned char)185;
    unsigned char b = '1';
    unsigned char c = '5';
    int d = (int) a^b^c;
    cout << hex << d;
}
