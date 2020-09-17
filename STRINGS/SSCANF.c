#include <stdio.h>

int main(void)
{
    int age;
    float salary;
    char string[] = "33 25000.00";

    sscanf(string, "%d %f\n", &age, &salary);  //? sscanf 拆分字符串输入
    // int d1, d2, n1, n2, i;
    // i = sscanf("123", "%d%n%n%d", &d1, &n1, &n2, &d2);

    printf("Age: %d Salary %f\n", age, salary);
}


        //    char *p;
        //    int n;

        //    errno = 0;
        //    n = scanf("%m[a-z]", &p);
        //    if (n == 1) {
        //        printf("read: %s\n", p);
        //        free(p);
        //    } else if (errno != 0) {
        //        perror("scanf");
        //    } else {
        //        fprintf(stderr, "No matching characters\n");
        //    }
