#include "public.hpp"

int main()
{
    int low = 0, high = N - 1;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = N - i - 1;
    }
    cout << "before: ";
    Show(arr);

    // QuickSortTest(arr, low, high);
    // BubbleSortTest(arr);
    MergeSortTest(arr, N);

    cout << "after:  ";
    Show(arr);

    return 0;
}

int QuickSortTest(int arr[], int low, int high)
{
    QuickSort(arr, low, high);
    return 0;
}

int BubbleSortTest(int arr[])
{
    BubbleSort(arr);
    return 0;
}

int MergeSortTest(int arr[], int len)
{
    MergeSort(arr, len);
    return 0;
}