#include "public.hpp"

int main()
{
    int arryA[] = {1, 5, 2, 6, 7, 8, 4, 9};
    int arryB[] = {1, 2, 3, 5, 6, 7, 8, 9};

    int value = 0;
    cout << "please input the value you want search: ";
    cin >> value;

    int ret1 = SequenceSearch(arryA, value, sizeof(arryA) / sizeof(arryA[0]));
    cout << "the position you search in arryA is: " << ret1 << endl;

    int ret2 = BinarySearch(arryB, value, 0, sizeof(arryB) / sizeof(arryB[0]));
    cout << "the position you search in arryB is: " << ret2 << endl;
    
    return 0;
}