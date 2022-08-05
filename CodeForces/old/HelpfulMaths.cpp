/*
 * 339A Helpful Maths
 * Jiawei Wang
 * 16 May 2021
 */

#include <iostream>
#include <string>
#include <vector>

using namespace::std;


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
    // This program support any number (required 1, 2 and 3 only)
    string stmt;
    string snumber;
    vector<int> ivec;
    getline(cin, stmt);
    
    int ctimes = 0;
    for (char c : stmt) {
	ctimes++;
	if ((int)c <= 57 && (int)c >= 48) {
	    snumber += c;
	    if (ctimes == stmt.size()) ivec.push_back(stoi(snumber));
	    continue;
	}
	ivec.push_back(stoi(snumber));
	snumber = "";
    }

    if (ivec.size() == 1) {
	cout << ivec[0];
	return 0;
    }

    // Using QuickSort 
    QuickSort(ivec, 0, ivec.size() - 1);
    int times = 0;
    for (int i : ivec) {
	if (times == ivec.size()-1) {
	    cout << i;
	    break;
	}
	cout << i << "+";
	times++;
    }

    return 0;

}
