#include <stdio.h>
#include <string.h>
//How to use strlen() function to count number of strings and output the strings

int main(void)
{
    char book_title[] = "Jamsa's 1001 C/C++ Tips";

    printf("%s contains %ld characters\n",
           book_title, strlen(book_title));  //Jamsa's 1001 C/C++ Tips contains 23 characters

    return 0;
}
