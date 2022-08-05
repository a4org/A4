/*
 * 706B Interesting Drink
 * Jiawei Wang
 * 19 May 2021
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int b_s(vector<int> &vi, vector<int>::iterator vib, vector<int>::iterator vie, int target) {
    auto mid = vib + (vie - vib) / 2;

    if (target < *vi.begin()) return 0;
    if (target >= *(vi.end()-1)) return vi.size();

    if (vib == vie - 1 && *vib != target) {
	return vib - vi.begin() + 1;
    }

    if (target > *mid){
	return b_s(vi, mid, vie, target);
    } else if (target < *mid) {
	return b_s(vi, vib, mid, target);
    } else {
	return mid - vi.begin() + 1;
    }

}
 
int main() {
    int nshops;
    cin >> nshops;

    vector<int> sprice;
    for (int i = 0; i < nshops; i++) {
	int price;
	cin >> price;
	sprice.push_back(price);
    }
    sort(sprice.begin(), sprice.end());

    int days;
    cin >> days;
    vector<int> dailyC;
    for (int i = 0; i < days; i++) {
	int dm; // daily money
	cin >> dm;
	dailyC.push_back(dm);
    }

    for (int d : dailyC) {
	int ans = b_s(sprice, sprice.begin(), sprice.end(), d);
	cout << ans << endl;
    }

}
