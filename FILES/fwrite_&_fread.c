#include <stdio.h>
// #include <stdlib.h>
#include <assert.h>

// enum { SIZE = 5 };
#define SIZE 5

// fwrite与fread用于写入和读出二进制文件，注意成对使用
int main(void)
{
    double a[SIZE] = {1, 2, 3, 4, 5};
    int i, r1;

    FILE *f1 = fopen("file.bin", "wb");
    assert(f1 != NULL);
    r1 = fwrite(a, sizeof a[0], SIZE, f1);
    printf("wrote %d elements out of %d requested\n", r1, SIZE);
    fclose(f1);

    double b[SIZE];
    FILE *f2 = fopen("file.bin", "rb");
    int r2   = fread(b, sizeof b[0], SIZE, f2);
    fclose(f2);

    printf("read back: ");
    for (i = 0; i < r2; i++)
        printf("%f ", b[i]);

    printf("\n");

    return 0;
}
