#include "public.hpp"

int Paritition(int arr[], int low, int high)
{
    int pivot = arr[low];
    while (low < high)
    {
        if (arr[high] >= pivot)
        {
            --high;
        }
        arr[low] = arr[high];
        if (arr[low] <= pivot)
        {
            ++low;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = Paritition(arr, low, high);
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
    }
}
