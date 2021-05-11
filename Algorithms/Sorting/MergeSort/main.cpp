#include <iostream>

#include "MergeSort/MergeSort.h"

using namespace::std;

int main()
{
    int A[] = {9, 27, 3 ,5 , 23, 7, 19, 2, 11, 3, 8, 10, 2, 3, 3, 3};
    int numberOfElements;

    numberOfElements = sizeof(A) / sizeof(A[0]);

    for (int i=0; i < numberOfElements; i++) cout << A[i] << " ";
    cout << "\n";

    MergeSort(A, numberOfElements);

    for (int j=0; j < numberOfElements; j++) cout << A[j] << " ";
    cout << endl;

    // 9 27 3 5 23 7 19 2 11 3 8 10 2 3 3 3
    // 2 2 3 3 3 3 3 5 7 8 9 10 11 19 23 27

    return 0;
} 
