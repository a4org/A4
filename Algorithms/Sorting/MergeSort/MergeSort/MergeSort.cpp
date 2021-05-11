#include<iostream>

using namespace::std;

void Merge(int* A, int* L, int leftCount, int* R, int rightCount)
{
    int i, j, k;
    i = 0, j = 0, k = 0;

    while (i < leftCount && j < rightCount)
    {
        if(R[j] < L[i]) A[k++] = R[j++];
        else A[k++] = L[i++];
    }

    // last check
    while (i < leftCount) A[k++] = L[i++];
    while (j < rightCount) A[k++] = R[j++];

}

void MergeSort(int* A, int n)
{
    int mid, *L, *R;

    if (n < 2) return;

    mid = n / 2;

    L = new int[mid];
    R = new int[n - mid];

    for(int i = 0; i < mid; i++) L[i] = A[i];
    for(int j = mid; j < n; j++) R[j-mid] = A[j];

    MergeSort(L, mid);
    MergeSort(R, n-mid);

    Merge(A, L, mid, R, n-mid);

    delete [] R;
    delete [] L;

}
