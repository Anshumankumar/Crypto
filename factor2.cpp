#include <iostream>
#include <stdio.h>
#include <gmp.h>

using namespace std;

int main()
{
    cout <<"Trying to factor N\n";
    mpz_t N,rootN,tmp,tmp2,p,q,A,nn;
    mpz_init (N);mpz_init(rootN);;mpz_init(tmp);mpz_init(tmp2);mpz_init(p);
    mpz_init(q);
    mpz_init(A);mpz_init(nn);
    mpz_set_str(N,
    "72006226374735042527956443552558373833808445147399984182665305798191 \
    63556901883377904234086641876639384851752649940178970835240791356868 \
    77441155132015188279331812309091996246361896836573643119174094961348 \
    52463970788523879939683923036467667022162701835329944324119217381272 \
    9276147530748597302192751375739387929",10);
    mpz_set(nn,N);
    mpz_mul_ui(N,nn,6);
    mpz_sqrt(tmp,N);
    mpz_add_ui (rootN,tmp,1);
    mpz_mul(tmp,rootN,rootN);
    mpz_sub(tmp2,tmp,N);
    mpz_sqrt(tmp,tmp2);
    mpz_add(q,tmp,rootN);
    mpz_sub(p,rootN,tmp);
    mpz_mul(tmp,p,q);
    mpz_cdiv_q_ui (q,q,2);
    mpz_cdiv_q_ui (p,p,3);
    char * answer;
    answer = mpz_get_str (NULL,10,p);
    cout << answer << endl;
    cout << mpz_get_str(NULL,10,q);
}
