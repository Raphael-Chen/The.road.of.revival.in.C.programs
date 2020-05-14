#include <stdio.h>
#include <stdlib.h>
//Duplicate RET_EXIT.C


//Usage: ./a.out file_name
int main(int argc, char *argv[])
{
    char line[255]; // Line read from the file

    FILE *fp = NULL;
    fp = fopen(argv[1], "r");

    if ( NULL != fp )
    {
        while (fgets(line, sizeof(line), fp))
            fputs(line, stdout);
        fclose(fp);

        exit(0); // Successful
    }
    else
    {
        printf("Cannot open %s\n", argv[1]);
        exit(1);
    }
}
