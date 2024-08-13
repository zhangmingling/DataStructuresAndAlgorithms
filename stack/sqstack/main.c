#include <stdio.h>
#include "sqstack.h"

int main(int argc, const char *argv[])
{
    sqstack *s;
    s = stack_create(100);
    if (s == NULL)
    {
        return -1;
    }
    printf("top is: %d\n", get_top(s));
    stack_push(s, 10);
    printf("top is: %d\n", get_top(s));
    stack_push(s, 20);
    printf("top is: %d\n", get_top(s));
    stack_push(s, 30);
    printf("top is: %d\n", get_top(s));

    while (!stack_empty(s))
    {
        printf("pop:%d\n", stack_pop(s));
    }
    stack_free(s);
    return 0;
}