#include <stdio.h>

// #define FILE_NAME "\\CONFIG.SYS"
#define FILE_NAME "/etc/passwd"

int main(void)
{
    FILE *input;
    int letter;

    input = fopen( FILE_NAME, "r" );
    if ( input == NULL )
        printf("Error opening %s.\n", FILE_NAME );
    else
    {
        printf("Current position is byte %ld\n\n", ftell(input));

        // Read and write each character in the file
        while ((letter = fgetc(input)) != EOF)
            fputc(letter, stdout);

        printf("\nCurrent position is byte %ld\n", ftell(input));

        fclose(input); // Close the input file
    }

    return 0;
}
