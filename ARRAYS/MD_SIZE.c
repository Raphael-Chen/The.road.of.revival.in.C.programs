#include <stdio.h>

int main(void)
{
    int box[3][3];

    float year_sales[52][5];

    char pages[40][60][20];

    printf("Bytes to hold int box[3][3] %ld bytes\n", sizeof(box)); //3  * 3 * sizeof(int)
    printf("Bytes to hold float year_sales[52][5] %ld bytes\n",     //52 * 2 * sizeof(float)
           sizeof(year_sales));
    printf("Bytes to hold char pages[40][60][20] %ld bytes\n",      //40 * 60 * 20 * sizeof(char)
           sizeof(pages));

    return 0;
}
