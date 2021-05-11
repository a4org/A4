#include <vector>
#include <iostream>

using namespace std;

size_t left(size_t i) {
    return 2*i;
}

size_t right(size_t i) {
    return 2*i + 1;
}

void maxHeapify(vector<int> &A, size_t i, size_t length) {
    // the key to maintaining the max-heap property
    size_t largest;
    size_t l = left(i);
    size_t r = right(i);
    if (l<=length && A[l]>A[i]) largest = l;
    else largest = i;
    if (r<=length && A[r]>A[largest]) largest = r;

    if(largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(A, largest, length);
    }
}

void buildMaxheap(vector<int> &A) {
    // produced a max heap from input array
    size_t length = A.size();
    for(size_t i= A.size()/2; i>=1; i--) {
        maxHeapify(A, i, length);
    }
}

void HeapSort(vector<int> &A) {
    // sorts an array in place
    buildMaxheap(A);
    int length = A.size();
    for (size_t i=A.size(); i>=2; i--) {
        swap(A[1], A[i]);
        length = length - 1;
        maxHeapify(A, 1, length);
    }
}


int main() {
    vector<int> A = {1, 4, 2, 9, 5, 3, 7, 6, 10, 24, 18};
    HeapSort(A);

    for (int a : A) {
        cout << a << " ";
    }
}













