#include <vector>
#include <iostream>

using namespace std;

int Partition(vector<int> &A, int p, int q) {
    int x = A[p];
    int i = p;
    for (int j = p + 1; j <= q; j++) {
        if(A[j] <= x) {
            i = i + 1;
            swap(A[i], A[j]);
        }
    }
    swap(A[p], A[i]);
    return i;
}


void QuickSort(vector<int> &A, int p, int r)  {
    if (p < r) {
        int q = Partition(A, p, r);
        QuickSort(A, p, q-1);
        QuickSort(A, q+1, r);
    }

}

int main() {
     vector<int> A = {2, 4, 6, 7, 5, 1, 9};
     QuickSort(A, 0, 7);

     for (int i : A) {
         cout << i << " ";
     }

 }
