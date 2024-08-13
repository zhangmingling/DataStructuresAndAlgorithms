#include "sqlist.h"

sqlink list_create()
{
    // malloc
    sqlink L;
    L = (sqlink)malloc(sizeof(sqlist));
    if (L == NULL)
    {
        printf("list malloc failed!\n");
        return L;
    }
    // initialize
    memset(L, 0, sizeof(sqlist));
    L->last = -1;
    // return
    return L;
}

int list_delete(sqlink L)
{
    if (L == NULL)
    {
        return -1;
    }
    free(L);
    L = NULL;
    return 0;
}

int list_clear(sqlink L)
{
    if (L == NULL)
    {
        return -1;
    }
    memset(L, 0, sizeof(sqlist));
    L->last = -1;
    return 0;
}

int list_isEmpty(sqlink L)
{
    if (L->last == -1)
    {
        return 1;
    }
    return 0;
}

int list_lenth(sqlink L)
{
    if (L == NULL)
    {
        return -1;
    }
    return L->last + 1;
}

int list_locate(sqlink L, data_t value)
{
    if (L == NULL)
    {
        return -1;
    }
    for (int i = 0; i < L->last; i++)
    {
        if (L->data[i] == value)
        {
            printf("the value:%d is existed and pos = %d\n", value, i);
            return i;
        }
        }
    printf("the value:%d is not existed\n", value);
    return 0;
}

int list_insert(sqlink L, data_t value, int pos)
{
    if (L->last == N - 1)
    {
        printf("list if full\n");
        return -1;
    }

    if (pos < 0 || pos > L->last + 1)
    {
        printf("pos is invalid\n");
        return -1;
    }

    for (int i = L->last; i >= pos; i--)
    {
        L->data[i + 1] = L->data[i];
    }
    L->data[pos] = value;
    L->last++;
    return 0;
}

int list_show(sqlink L)
{
    if (L == NULL)
    {
        return -1;
    }
    if (L->last == -1)
    {
        printf("list is empty\n");
    }
    for (int i = 0; i <= L->last; i++)
    {
        printf("%d ", L->data[i]);
    }
    puts("");
    return 0;
}