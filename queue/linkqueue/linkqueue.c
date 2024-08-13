#include "linkqueue.h"

linkqueue *queue_create()
{
    linkqueue *lq;
    lq = (linkqueue *)malloc(sizeof(linkqueue));
    if (lq == NULL)
    {
        printf("malloc linkqueue failed\n");
        return NULL;
    }

    lq->front = lq->rear = (linklist)malloc(sizeof(listnode));
    if (lq->front == NULL || lq->rear == NULL)
    {
        printf("malloc listnode failed\n");
        return NULL;
    }

    lq->front->data = 0;
    lq->front->next = NULL;

    return lq;
}
int enqueue(linkqueue *lq, datatype x)
{
    if (lq == NULL)
    {
        printf("lq is NULL\n");
        return -1;
    }

    linklist p;
    p = (linklist)malloc(sizeof(listnode));
    if (p == NULL)
    {
        printf("malloc listnode p failed\n");
        return -1;
    }
    p->data = x;
    p->next = NULL;

    lq->rear->next = p;
    lq->rear = p;
    return 0;
}
datatype dequeue(linkqueue *lq)
{
    if (lq == NULL)
    {
        printf("lq is NULL\n");
        return -1;
    }

    linklist p;
    p = lq->front;
    lq->front = p->next;
    free(p);
    p = NULL;
    return (lq->front->data);
}
int queue_empty(linkqueue *lq)
{
    if (lq == NULL)
    {
        printf("lq is NULL\n");
        return -1;
    }

    return (lq->front == lq->rear ? 1 : 0);
}
int queue_clear(linkqueue *lq)
{
    if (lq == NULL)
    {
        printf("lq is NULL\n");
        return -1;
    }

    linklist p;
    while (lq->front->next)
    {
        p = lq->front;
        lq->front = p->next;
        printf("free of clear: %d\n", p->data);
        free(p);
        p = NULL;
    }
    return 0;
}
linkqueue *queue_free(linkqueue *lq)
{
    if (lq == NULL)
    {
        printf("lq is NULL\n");
        return NULL;
    }

    linklist p;

    while (lq->front)
    {
        p = lq->front;
        lq->front = p->next;
        printf("free: %d\n", p->data);
        free(p);
        p = NULL;
    }
    free(lq);
    lq = NULL;
    return NULL;
}