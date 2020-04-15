#include <stdio.h>

void hello_world(void)
{
    printf("Hello, world!\n");
}

void hello_count(int message_count)
{
    int counter;

    for (counter = 1; counter <= message_count; counter++)
        hello_world();
} 

int main(void)
{
    printf("Display the message twice\n");
    hello_count(2);
    printf("Display the message five times\n");
    hello_count(5);

    return 0;
}
