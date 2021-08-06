#include <stdio.h>

int main(void)
{
    FILE *fp;

    int age;
    float salary;
    char name[64] = { '\0' };

    fp = fopen("DATA.DAT", "w");
    if ( fp == NULL )
        printf("Error opening DATA.DAT for output\n");
    else
    {
        fprintf(fp, "33 35000.0 Kris");
        fclose(fp);

        fp = fopen("DATA.DAT", "r");
        if ( fp == NULL )
            printf("Error opening DATA.DAT for input\n");
        else
        {
            fscanf(fp, "%d %f %s", &age, &salary, name);
            printf("Age %d Salary %f Name %s\n", age, salary, name);
            fclose(fp);
        }
    }

    return 0; 
}
