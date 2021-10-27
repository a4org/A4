/*
 * LeetCode 75 Sort Colors
 * Medium
 * Jiawei Wang
 * 2021.10.27
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // #1 QuickSort
    void sortColors1(vector<int>& nums) {
	int n = nums.size()-1;
	QuickSort(nums, 0, n);
    }

    // #2 Heap Sort 
    void sortColors2(vector<int>& A) {
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

private:
    // helper functions of quicksort
    void QuickSort(vector<int>& A, int p, int r) {
	if (p < r) {
	    int q = partition(A, p, r);
	    QuickSort(A, p, q-1);
	    QuickSort(A, q+1, r);
	}
    }
    int partition(vector<int>& A, int p, int q) {
	// (p, i-1) i (i+1, j)
	//     <         <
	int x = A[p];
	int i = p; 
	for (int j = p+1; j <= q; j++) {
	    if (A[j] <= x) {
		// find one greater
		i = i + 1;
		swap(A[i], A[j]);
	    } 
	}
	swap(A[p], A[i]);
	return i;
    }


    // helper functions of heap sort
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

};

