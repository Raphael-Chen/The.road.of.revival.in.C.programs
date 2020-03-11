#include <stdio.h>
#include <time.h>

int main(void)
{
    tzset();
    printf("Difference between local and GMT is %ld hours\n",
           timezone / ( long int )3600);
}
