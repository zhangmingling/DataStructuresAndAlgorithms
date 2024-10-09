#ifndef PUBLIC_HPP
#define PUBLIC_HPP

#include <iostream>
using namespace std;

#define N 10

int Show(int arr[]);

int BubbleSortTest(int arr[]);
void BubbleSort(int arr[]);

int QuickSortTest(int arr[], int low, int high);
void QuickSort(int arr[], int low, int high);
int Paritition(int arr[], int low, int high);

int MergeSortTest(int arr[], int len);
void MergeSort(int arr[], int len);
void Split(int arr[], int tempArry[], int start, int end);
void Sort(int arr[], int tempArry[], int start, int mid, int end);

#endif