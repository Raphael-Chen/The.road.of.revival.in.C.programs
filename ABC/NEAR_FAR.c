//[Bug]There is a bug for output format

#include <stdio.h>

int main(void)
{
    // char *near_title = "Jamsa's 1001 C & C++ Tips";
    const char* near_title = "Jamsa's 1001 C & C++ Tips";
    // char far *far_title = "Jamsa's 1001 C & C++ Tips";
    const char *far_title = "Jamsa's 1001 C & C++ Tips";

    // printf("The book's title: %Ns\n", near_title);
    printf("The book's title: %ns\n", near_title);
    printf("The book's title: %Fs\n", far_title);
}
