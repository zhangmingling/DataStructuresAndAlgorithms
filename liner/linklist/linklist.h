#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int data_t;
#define N 128

typedef struct node
{
    data_t data;
    struct node *next;
} listnode, *linklist;

linklist list_create();
int list_tail_insert(linklist H, data_t value);
int list_show(linklist H);
int list_insert(linklist H, data_t value, int pos);
linklist list_get(linklist H, int pos);
int list_delete(linklist H, int pos);
linklist list_free(linklist H);
int list_reverse(linklist H);
linklist list_adjmax(linklist H);
int list_merge(linklist H1, linklist H2);

#endif