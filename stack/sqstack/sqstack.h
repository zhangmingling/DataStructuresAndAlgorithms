#ifndef _SQSTACK_H_
#define _SQSTACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 128

typedef int data_t;
typedef struct
{
    data_t *data;
    int maxlen;
    int top;
} sqstack;

sqstack *stack_create(int len);
int stack_clear(sqstack *s);
int stack_empty(sqstack *s);
int stack_full(sqstack *s);
int stack_push(sqstack *s, data_t value);
data_t stack_pop(sqstack *s);
data_t stack_top(sqstack *s);
int stack_free(sqstack *s);

#endif