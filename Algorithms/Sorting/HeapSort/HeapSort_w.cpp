#include <vector>
#include <iostream>

// https://alrightchiu.github.io/SecondRound/comparison-sort-heap-sortdui-ji-pai-xu-fa.html
using namespace::std;

void swap(int &p1, int &p2) {
    int tmp = p1;
    p1 = p2;
    p2 = tmp;
}

void MaxHeaptify(vector<int>& A, int root, int length) {
    // complete binary tree
    int left = 2*root;
    int right = 2*root + 1;

    int largest;

    if (left <= length && A[left] > A[root]) {
	largest = left;
    } else {
	largest = root;
    }

    if (right <= length && A[right] > A[largest]) {
	largest = right;
    }

    if (largest != root) {
	// we need to update the subtree
	swap(A[root], A[largest]);
	MaxHeaptify(A, largest, length);
    }
}

void BuildMaxHeap(vector<int>& A) {
    // from the last parent node to root
    for (int i = (int)A.size()/2; i >= 1; i--) {
	MaxHeaptify(A, i, (int)A.size()-1);
    }
}

void HeapSort(vector<int>& A) {
    A.insert(A.begin(), 0);
    BuildMaxHeap(A);

    int size = (int)A.size() - 1;
    for (int i = (int)A.size()-1; i >= 2; i--) {
	swap(A[1], A[i]);
	size--;
	MaxHeaptify(A, 1, size);
    }
    A.erase(A.begin());
}

void PrintArray(std::vector<int> &array){
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

    int arr[] = {9, 4, 1, 6, 7, 3, 8, 2, 5};
    std::vector<int> array(arr, arr+sizeof(arr)/sizeof(int));

    std::cout << "original:\n";
    PrintArray(array);

    HeapSort(array);

    std::cout << "sorted:\n";
    PrintArray(array);

    return 0;
}

