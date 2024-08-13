#include "public.hpp"

int SequenceSearch(int arry[], int vaule, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arry[i] == vaule)
        {
            return i;
        }
    }
    return -1;
}