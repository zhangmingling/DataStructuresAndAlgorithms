#include "hash.h"

int main()
{
    hash *HT;
    int data[] = {23, 34, 14, 38, 46, 16, 68, 15, 7, 31, 26};
    int key;
    linklist r;

    HT = hash_create();
    if (HT == NULL)
    {
        return -1;
    }
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
    {
        hash_insert(HT, data[i]);
    }

    printf("input:");
    scanf("%d", &key);
    r = hash_search(HT, key);
    if (r == NULL)
    {
        printf("not found\n");
    }
    else
    {
        printf("key:%d r->key:%d\n", key, r->key);
    }
    return 0;
}