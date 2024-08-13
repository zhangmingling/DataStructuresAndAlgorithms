#include "linklist.h"

linklist list_create()
{
    // malloc
    linklist H;
    H = (linklist)malloc(sizeof(listnode));
    if (H == NULL)
    {
        printf("linklist malloc failed!\n");
        return H;
    }
    // initialize
    H->data = 0;
    H->next = NULL;
    // return
    return H;
}
int list_tail_insert(linklist H, data_t value)
{
    if (H == NULL)
    {
        printf("H is NULL\n");
        return -1;
    }
    // new node
    linklist p;
    p = (linklist)malloc(sizeof(listnode));
    if (p == NULL)
    {
        printf("linklist malloc failed!\n");
        return -1;
    }
    p->data = value;
    p->next = NULL;
    // find tail node
    linklist q;
    q = H;
    while (q->next != NULL)
    {
        q = q->next;
    }
    // insert
    q->next = p;

    return 0;
}
int list_show(linklist H)
{
    if (H == NULL)
    {
        printf("H is NULL\n");
        return -1;
    }

    linklist q;
    q = H;
    while (q->next != NULL)
    {
        printf("%d ", q->next->data);
        q = q->next;
    }
    puts("");
    return 0;
}
linklist list_get(linklist H, int pos)
{
    if (H == NULL)
    {
        printf("H is NULL\n");
        return NULL;
    }
    if (pos == -1)
    {
        return H;
    }
    if (pos < -1)
    {
        printf("pos is invalid\n");
        return NULL;
    }
    linklist p;
    p = H;
    for (int i = 0; i < pos + 1; i++)
    {
        p = p->next;
        if (p == NULL)
        {
            printf("pos %d is invalid\n", pos);
            break;
        }
    }
    if (p != NULL)
    {
        printf("the pos %d is %d\n", pos, p->data);
    }
    return p;
}
int list_insert(linklist H, data_t value, int pos)
{
    if (H == NULL)
    {
        printf("H is NULL\n");
        return -1;
    }

    // locate node pos-1
    linklist p = list_get(H, pos - 1);
    if (p == NULL)
    {
        return -1;
    }

    // new node q
    linklist q = (linklist)malloc(sizeof(listnode));
    if (q == NULL)
    {
        printf("malloc failed\n");
        return -1;
    }

    q->data = value;
    q->next = NULL;

    // insert
    q->next = p->next;
    p->next = q;

    return 0;
}
int list_delete(linklist H, int pos)
{
    // Check the parameters
    if (H == NULL)
    {
        printf("H is NULL\n");
        return -1;
    }

    // locate prior
    linklist p = list_get(H, pos - 1);
    if (p == NULL)
    {
        return -1;
    }

    if (p->next == NULL)
    {
        printf("delete pos is invalid\n");
        return -1;
    }

    // update list
    linklist q;
    q = p->next;
    p->next = q->next;

    // free
    printf("delete pos is %d\n", pos);
    printf("free data is %d\n", q->data);
    free(q);
    q = NULL;

    return 0;
}
linklist list_free(linklist H)
{
    if (H == NULL)
    {
        return NULL;
    }

    linklist p;

    printf("free:");
    while (H != NULL)
    {
        p = H;
        H = H->next;
        printf("%d ", p->data);
        free(p);
    }
    puts("");

    return NULL;
}
int list_reverse(linklist H)
{
    if (H == NULL)
    {
        printf("H is invalid\n");
        return -1;
    }

    if (H->next == NULL || H->next->next == NULL)
    {
        return 0;
    }

    linklist p = H->next->next;
    H->next->next = NULL;

    while (p != NULL)
    {
        list_insert(H, p->data, 0);
        p = p->next;
    }

    return 0;
}
linklist list_adjmax(linklist H)
{
    if (H == NULL)
    {
        printf("H is invalid\n");
        return NULL;
    }

    if (H->next == NULL || H->next->next == NULL || H->next->next->next == NULL)
    {
        return H;
    }

    linklist p, q, r;
    p = H->next;
    q = p->next;
    r = q;
    int max = 0;

    while (q != NULL)
    {
        int sum = p->data + q->data;
        if (sum > max)
        {
            max = sum;
            r = p;
        }
        p = p->next;
        q = q->next;
    }
    printf("max = %d\n", max);

    return r;
}
int list_merge(linklist H1, linklist H2)
{
    if (H1 == NULL || H2 == NULL)
    {
        return -1;
    }

    linklist p, q, r;
    p = H1->next;
    q = H2->next;
    r = H1;

    H1->next = NULL;
    H2->next = NULL;

    while (p && q)
    {
        if (p->data < q->data)
        {
            r->next = p;
            p = p->next;
            r = r->next;
            r->next = NULL;
        }
        else
        {
            r->next = q;
            q = q->next;
            r = r->next;
            r->next = NULL;
        }
    }
    if (p == NULL)
    {
        r->next = q;
    }
    else
    {
        r->next = p;
    }

    return 0;
}