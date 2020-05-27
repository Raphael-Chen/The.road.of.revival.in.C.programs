#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void )
{
    char name[100];
    char *description = NULL;

    strcpy(name, "Zara Ali");

    /* 动态分配内存 */
    description = (char *)malloc(30 * sizeof(char));
    if (description == NULL)
    {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    }
    else
    {
        strcpy(description, "Zara ali a DPS student.");
    }
    printf( "description is %ld byte.\n", strlen( description ) );

    /* 假设您想要存储更大的描述信息 */
    description = (char *)realloc(description, 100 * sizeof(char));
    if (description == NULL)
    {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    }
    else
    {
        strcat(description, "She is in class 10th");
    }

    printf("Name = %s\n", name);
    printf("Description: %s\n", description);

    /* 使用 free() 函数释放内存 */
    free(description);

    return 0;
}
