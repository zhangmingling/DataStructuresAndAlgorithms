#include "public.hpp"

int main()
{
    int arryA[] = {9, 5, 2, 8, 3, 7, 6, 4, 1};
    int arryB[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int lenA = sizeof(arryA) / sizeof(arryA[0]);
    int lenB = sizeof(arryB) / sizeof(arryB[0]);

    cout << lenA << " " << lenB << endl;
    int value = 0;
    cout << "value:";
    cin >> value;

    cout << "SequenceSearch position:" << SequenceSearch(arryA, value, lenA) << endl;

    cout << "BinarySearch1 position:" << BinarySearch1(arryB, value, 0, lenB - 1) << endl;

    cout << "BinarySearch2 position:" << BinarySearch2(arryB, value, 0, lenB - 1) << endl;

    return 0;
}