#include <iostream>
#include <stdio.h>
#include <gmp.h>

using namespace std;

int main()
{
    cout <<"Trying to factor N\n";
    mpz_t N,rootN,tmp,tmp2,p,q,A,C;
    mpz_init (N);mpz_init(rootN);;mpz_init(tmp);mpz_init(tmp2);mpz_init(p);
    mpz_init(q);
    mpz_init(A);mpz_init(C);
    mpz_set_str(N,
    "17976931348623159077293051907890247336179769789423065727343008115 \
    77326758055056206869853794492129829595855013875371640157101398586 \
    47833778606925583497541085196591615128057575940752635007475935288 \
    71082364994994077189561705436114947486504671101510156394068052754 \
    0071584560878577663743040086340742855278549092581",10); 
    mpz_sqrt(tmp,N);
    mpz_add_ui (rootN,tmp,1);
    int s = 1<<20;
    int k =0;
    while (k < s)
    {    
        mpz_mul(tmp,rootN,rootN);
        mpz_sub(tmp2,tmp,N);
        mpz_sqrt(tmp,tmp2);
        mpz_add(q,tmp,rootN);
        mpz_sub(p,rootN,tmp);
        mpz_mul(tmp,p,q);
        if (mpz_cmp (tmp,N) == 0)
        {
            break;
        }
        mpz_set(tmp2,rootN);
        mpz_add_ui (rootN,tmp2, 1);
        k++;
    }
    char * answer;
    answer = mpz_get_str (NULL,10,tmp);
    cout << answer << "\n";
    mpz_sub_ui (p,p,1);
    mpz_sub_ui (q,q,1);
    mpz_t e,theta;
    mpz_init(e);mpz_init(theta);
    mpz_mul(theta,p,q);
    k = 1;
    mpz_set_str(e,"65537",10);
    while (k)
    {
        mpz_mul_ui(tmp,theta,k);
        mpz_add_ui(tmp,tmp,1);
        mpz_tdiv_r(tmp2,tmp,e);
        if (mpz_cmp_ui(tmp2,0) ==0 ) break;
        cout << k << endl;
        k++;
    }
    mpz_tdiv_q(tmp2,tmp,e);
    mpz_t alp;
    mpz_init(alp);
    mpz_set_str(alp,
    "22096451867410381776306561134883418017410069787892831071731839143676135600120538004282329650473509424343946219751512256465839967942889460764542040581564748988013734864120452325229320176487916666402997509188729971690526083222067771600019329260870009579993724077458967773697817571267229951148662959627934791540",10);
    mpz_powm (tmp, alp, tmp2, N);
    cout <<hex << mpz_get_str(NULL,10,tmp);
}
