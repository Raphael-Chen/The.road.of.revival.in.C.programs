#include <stdio.h>

void unsigned_limit( void )
{
   // printf( "", __ ); __FUNC__
    unsigned char  c;
    unsigned short s;
    unsigned int   i;
    unsigned long long ll;
    
    printf( "sizeof is: %ld, %ld, %ld, %ld\n", sizeof(c), sizeof(s), sizeof(i), sizeof(ll)  );

    c = 0xFF;                // Set every bit to 1
    s = 0xFFFF;
    i = 0xFFFFFFFF;
    ll = 0xFFFFFFFFFFFFFFFF;
    
    printf( "Max c,s,i,ll is: %d, %d, %u, %llu\n", c, s, i, ll );
    
    c = c + 1;
    s = s + 1;
    i = i + 1;
    ll = ll + 1;

    printf( "After plus one, overflow happen\n c,s,i,ll is: %d, %d, %u, %llu\n", c, s, i, ll );

}

void signed_limit( void )
{

}

int main( void )
{
    unsigned_limit();

    return 0;
}

