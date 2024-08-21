#include "public.hpp"

int BinarySearch1(int arry[], int vaule, int low, int high)
{
    int mid = low + ((high - low) / 2);
    // int mid = (high + low )/ 2;
    if (arry[mid] == vaule)
    {
        return mid;
    }
    else if (arry[mid] < vaule)
    {
        return BinarySearch1(arry, vaule, mid + 1, high);
    }
    else if (arry[mid] > vaule)
    {
        return BinarySearch1(arry, vaule, low, mid - 1);
    }
    else
    {
        return -1;
    }
}

int BinarySearch2(int arry[], int vaule, int low, int high)
{
    while (low <= high)
    {
        int mid = (high + low )/ 2;
        if (arry[mid] < vaule)
        {
            low = mid + 1;
        }
        else if (arry[mid] > vaule)
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}