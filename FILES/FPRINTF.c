#include <stdio.h>

int main(void)
{
    FILE *fp;

    int pages = 892;
    float price = 39.95;

    fp = fopen("FPRINTF.DAT", "w");
    if ( NULL != fp )
    {
        fprintf(fp, "Book Title: Jamsa's 1001 C & C++ Tips\n");
        fprintf(fp, "Pages: %d\n", pages);
        fprintf(fp, "Price: $%5.2f\n", price);
        fclose(fp);
    }
    else
        printf("Error opening FPRINTF.DAT\n");

    return 0;    
}
 