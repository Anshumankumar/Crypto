#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct hashtable
{
	long int index;
	mpz_t value;
};

int comp (const  void * a , const void *b)
{
	return mpz_cmp(((hashtable*)a)->value,((hashtable*)b)->value);
}
int main()
{
	mpz_t p,g,h,temp,temp2,kmp;
	mpz_init (p);
	mpz_init (g);
	mpz_init (h);
	mpz_init (temp);
	mpz_init (temp2);
	mpz_init (kmp);
	mpz_set_str(p,"13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084171",10);
	mpz_set_str(g,"11717829880366207009516117596335367088558084999998952205599979459063929499736583746670572176471460312928594829675428279466566527115212748467589894601965568",10);
	mpz_set_str(h,"3239475104050450443565264378728065788649097520952449527834792452971981976143292558073856937958553180532878928001494706097394108577585732452307673444020333",10);
	unsigned  long int b = 1<<20;
	unsigned long int k = ((unsigned long)1 << 40);
	//cout <<  k << "\n";
	mpz_set_ui(kmp,k);
	hashtable  *hasht;
	hasht = new hashtable[b];
    cout << "started making table\n";
	for (unsigned long i = 0 ; i< b ;i++)
	{
	    mpz_init(hasht[i].value);
		hasht[i].index=i;
		mpz_powm_ui(temp,g,i,p);
		mpz_invert(temp2,temp,p);
		mpz_mul (temp, h, temp2);
		mpz_fdiv_r (hasht[i].value,temp,p);
	}
    cout << "Table made \n";
	qsort (hasht, b, sizeof(hashtable), comp);	
    cout << "sorted \n";
	mpz_powm_ui(temp,g,b,p);
	hashtable *ans;	
	hashtable checker;
	mpz_init(checker.value);
    mpz_set_ui(checker.value,1);
	for (unsigned long i = 1 ; i< b ;i++)
	{
		mpz_mul(checker.value,checker.value,temp);
        mpz_fdiv_r (checker.value,checker.value,p);
		checker.index = i;
		ans = (hashtable*) bsearch (&checker,hasht, b, sizeof(hashtable),comp);
        if (ans != NULL)
        {
            break;
        }
	}
 //   cout << "got the answer";	
    unsigned long x =(*ans).index+checker.index*b;
   // cout << x<<endl;
   printf ("%lu\n",x);
}
