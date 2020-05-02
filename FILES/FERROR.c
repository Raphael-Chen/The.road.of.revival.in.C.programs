#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;

    char line[256];

    fp = fopen(argv[1], "r");
    if ( fp != NULL )
    {
        while (fgets(line, sizeof(line), fp))
        {
            if (ferror(fp))
            {
                fprintf(stderr, "Error reading from %s\n", argv[1]);
                exit(1);
            }
            else
            {
                fputs(line, stdout);
                if (ferror(fp))
                {
                    fprintf(stderr, "Error writing to stdout\n");
                    exit(1);
                }
            }
        }
    }
    else
        printf("Error opening %s\n", argv[1]);

    return 0;        
}
