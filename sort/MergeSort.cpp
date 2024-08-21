#include "public.hpp"
/*
使用malloc动态申请数组
优点:
灵活性高：可以处理不确定大小的数据集，适用于大小在运行时才知道的情况。
内存管理：动态分配的内存可以在不需要时通过free释放，有助于管理程序的内存使用。
缺点:
性能开销：每次调用malloc和free都有一定的性能开销，尤其是在频繁调用时。
忘记释放：如果忘记释放内存，可能会导致内存泄漏。

直接定义一个足够大的静态数组
优点:
性能更好：避免了动态内存分配和释放的开销。
简单易用：代码更简洁，不需要考虑内存管理问题。
缺点:
空间效率低：如果预先定义的数组过大，而实际处理的数据集较小，会造成不必要的内存占用。
不够灵活：对于数据规模未知或变化较大的情况不适用。
*/
void Split(int arr[], int tempArr[], int start, int end)
{
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    // int mid = (start + end) / 2;
    Split(arr, tempArr, start, mid);
    Split(arr, tempArr, mid + 1, end);
    Sort(arr, tempArr, start, mid, end);
}

void Sort(int arr[], int tempArr[], int start, int mid, int end)
{
    int start1 = start;
    int start2 = mid + 1;
    int p = start;
    while (start1 <= mid && start2 <= end)
        tempArr[p++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= mid)
        tempArr[p++] = arr[start1++];
    while (start2 <= end)
        tempArr[p++] = arr[start2++];
    for (p = start; p <= end; p++)
        arr[p] = tempArr[p];
}

void MergeSort(int arr[], const int len)
{
    if (int *tempArr = (int *)malloc(len * sizeof(int)))
    {
        Split(arr, tempArr, 0, len - 1);
        free(tempArr);
    }
    // int tempArr[len];
    // Split(arr, tempArr, 0, len - 1);
}
