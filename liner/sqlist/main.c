#include "sqlist.h"

void insert_test();

int main(int argc, const char *argv[])
{
    insert_test();
    return 0;
}

void insert_test()
{
    sqlink L;
    L = list_create();
    if (L == NULL)
    {
        return;
    }
    list_insert(L, 10, 0);
    list_insert(L, 20, 1);
    list_insert(L, 30, 2);
    list_insert(L, 40, 3);
    list_insert(L, 50, 4);
    list_insert(L, 50, 2);
    list_insert(L, 50, 128);

    printf("last = %d\n", L->last);

    printf("%d\n", list_isEmpty(L));

    list_show(L);

    int len = list_lenth(L);
    printf("lenth = %d\n", len);
    
    list_locate(L, 10);
    list_locate(L, 20);
    list_locate(L, 30);
    list_locate(L, 40);
    list_locate(L, 50);


    // list_delete(L);
}