#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char line[255]; // Line read from the file

    FILE *fp = NULL ;

    fp = fopen(argv[1], "r");
    if ( NULL != fp )
    {
        while (fgets(line, sizeof(line), fp))
            fputs(line, stdout);
        fclose(fp);

        return (0); // Successful
    }
    else
    {
        printf("Cannot open %s\n", argv[1]);
        return (1);
    }
}
