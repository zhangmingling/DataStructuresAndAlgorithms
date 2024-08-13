#include "linklist.h"

int insert_test();
int delete_test();
int free_test();
int reverse_test();
int adjmax_test();
int merge_test();

int main(int argc, const char *argv[])
{
    // insert_test();
    // delete_test();
    // free_test();
    // reverse_test();
    // adjmax_test();
    merge_test();
    return 0;
}

int insert_test()
{
    linklist H;
    int value;
    H = list_create();
    if (H == NULL)
    {
        return -1;
    }
    printf("input:");
    while (1)
    {
        scanf("%d", &value);
        if (value == -1)
        {
            break;
        }
        list_tail_insert(H, value);
        printf("input:");
    }

    list_get(H, 0);
    list_get(H, 2);
    list_get(H, 3);

    list_show(H);

    list_get(H, 2);
    list_insert(H, 100, 2);

    list_show(H);

    list_get(H, 0);
    list_insert(H, 100, 0);

    list_show(H);

    list_get(H, 5);
    list_insert(H, 100, 5);

    list_show(H);

    return 0;
}

int delete_test()
{
    linklist H;
    int value;
    H = list_create();
    if (H == NULL)
    {
        return -1;
    }
    printf("input:");
    while (1)
    {
        scanf("%d", &value);
        if (value == -1)
        {
            break;
        }
        list_tail_insert(H, value);
        printf("input:");
    }
    list_show(H);
    list_delete(H, 0);
    list_show(H);
    list_delete(H, -1);
    list_show(H);
    list_delete(H, 5);
    list_show(H);

    return 0;
}

int free_test()
{
    linklist H;
    int value;
    H = list_create();
    if (H == NULL)
    {
        return -1;
    }
    printf("input:");
    while (1)
    {
        scanf("%d", &value);
        if (value == -1)
        {
            break;
        }
        list_tail_insert(H, value);
        printf("input:");
    }
    list_show(H);
    printf("H = %p\n", H);
    H = list_free(H);
    printf("H = %p\n", H);

    return 0;
}

int reverse_test()
{
    linklist H;
    int value;
    H = list_create();
    if (H == NULL)
    {
        return -1;
    }
    printf("input:");
    while (1)
    {
        scanf("%d", &value);
        if (value == -1)
        {
            break;
        }
        list_tail_insert(H, value);
        printf("input:");
    }
    list_show(H);
    list_reverse(H);
    list_show(H);
}

int adjmax_test()
{
    linklist H;
    int value;
    H = list_create();
    if (H == NULL)
    {
        return -1;
    }
    printf("input:");
    while (1)
    {
        scanf("%d", &value);
        if (value == -1)
        {
            break;
        }
        list_tail_insert(H, value);
        printf("input:");
    }
    list_show(H);
    linklist r = list_adjmax(H);
    if (r != NULL && r != H)
    {
        printf("r->data:%d\n", r->data);
    }
    list_free(H);
}

int merge_test()
{
    linklist H1, H2;
    int value1, value2;
    H1 = list_create();
    H2 = list_create();
    if (H1 == NULL || H2 == NULL)
    {
        return -1;
    }
    printf("H1 input:");
    while (1)
    {
        scanf("%d", &value1);
        if (value1 == -1)
        {
            break;
        }
        list_tail_insert(H1, value1);
        printf("H1 input:");
    }

    printf("H2 input:");
    while (1)
    {
        scanf("%d", &value2);
        if (value2 == -1)
        {
            break;
        }
        list_tail_insert(H2, value2);
        printf("H2 input:");
    }
    printf("H1: ");
    list_show(H1);
    printf("H2: ");
    list_show(H2);
    list_merge(H1, H2);
    printf("merge: ");
    list_show(H1);
}