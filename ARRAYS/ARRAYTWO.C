#include <stdio.h>

int main(void)
{
    int count[10];
    float salaries[5];
    long distances[10];

    printf("Address of the array count is %p &count is %p\n",
           count, &count);
    printf("Address of the array salaries is %p &count is %p\n",
           salaries, &salaries);
    printf("Address of the array distances is %p &distances is %p\n",
           distances, &distances);

    return 0;
}
