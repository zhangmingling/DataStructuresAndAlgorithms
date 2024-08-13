#ifndef _SQLIST_H_
#define _SQLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
typedef int data_t;
#define N 128
struct sqlist_t
{
    data_t data[N];
    int last;
};

typedef struct sqlist_t sqlist;
typedef struct sqlist_t *sqlint;
*/

typedef int data_t;
#define N 128

typedef struct
{
    data_t data[N];
    int last;
} sqlist, *sqlink;

sqlink list_create();
int list_delete(sqlink L);
int list_clear(sqlink L);
int list_isEmpty(sqlink L);
int list_lenth(sqlink L);
int list_locate(sqlink L, data_t value);
int list_insert(sqlink L, data_t value, int pos);
int list_show(sqlink L);

#endif