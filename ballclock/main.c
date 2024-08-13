#include "linkqueue.h"
#include "sqstack.h"

int check(linkqueue *lq)
{
    if (lq == NULL)
    {
        printf("lq is NULL\n");
        return -1;
    }
    linklist p;
    p = lq->front->next;
    while (p && p->next)
    {
        if (p->data < p->next->data)
        {
            p = p->next;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    linkqueue *lq;
    sqstack *s_hour, *s_five, *s_min;
    int value = 0, min = 0;
    lq = queue_create();
    s_hour = stack_create(11);
    s_five = stack_create(11);
    s_min = stack_create(4);
    if (lq == NULL || s_hour == NULL || s_five == NULL || s_min == NULL)
    {
        return -1;
    }

    for (int i = 1; i <= 27; i++)
    {
        enqueue(lq, i);
    }

    while (1)
    {
        min++;
        if (!queue_empty(lq))
        {
            value = dequeue(lq);
            if (!stack_full(s_min))
            {
                stack_push(s_min, value);
            }
            else
            {
                while (!stack_empty(s_min))
                {
                    enqueue(lq, stack_pop(s_min));
                }
                if (!stack_full(s_five))
                {
                    stack_push(s_five, value);
                }
                else
                {
                    while (!stack_empty(s_five))
                    {
                        enqueue(lq, stack_pop(s_five));
                    }
                    if (!stack_full(s_hour))
                    {
                        stack_push(s_hour, value);
                    }
                    else
                    {
                        while (!stack_empty(s_hour))
                        {
                            enqueue(lq, stack_pop(s_hour));
                        }
                        enqueue(lq, value);
                        if (check(lq) == 1)
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
    printf("total:%d\n", min);

    printf("dequeue:");
    while (!queue_empty(lq))
    {
        printf("%d ", dequeue(lq));
    }
    puts("");
    return 0;
}