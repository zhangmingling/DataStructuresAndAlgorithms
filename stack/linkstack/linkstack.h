#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef int data_t;
typedef struct node
{
    data_t data;
    struct node *next;
} listnode, *linkstack;

linkstack stack_create();
int stack_push(linkstack s, data_t value);
data_t stack_pop(linkstack s);
int stack_empty(linkstack s);
data_t stack_top(linkstack s);
linkstack stack_free(linkstack s);

#endif