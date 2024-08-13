#include "public.hpp"

int BinarySearch(int arry[], int vaule, int low, int high)
{
    int mid = (low + (high - low)) / 2;
    if (arry[mid] == vaule)
    {
        return mid;
    }
    if (arry[mid] < vaule)
    {
        return BinarySearch(arry, vaule, mid + 1, high);
    }
    if (arry[mid] > vaule)
    {
        return BinarySearch(arry, vaule, low, mid - 1);
    }
    return -1;
}