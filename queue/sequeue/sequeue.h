#ifndef _SEQUEUE_H_
#define _SEQUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 6
typedef int datatype;
typedef struct
{
    datatype data[N];
    int front;
    int rear;
} sequeue;

sequeue *queue_create();
int enqueue(sequeue *sq, datatype x);
datatype dequeue(sequeue *sq);
int queue_empty(sequeue *sq);
int queue_full(sequeue *sq);
int queue_clear(sequeue *sq);
sequeue *queue_free(sequeue *sq);

#endif