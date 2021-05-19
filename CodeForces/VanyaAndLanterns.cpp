/*
 * 492B Vanya and Lanterns
 * Jiawei Wang
 * 19 May 2021
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace::std;

int main() {
    int num, len;
    cin >> num >> len;

    vector<int> vi;
    for (int i = 0; i < num; i++) {
	int pos;
	cin >> pos;
	vi.push_back(pos);
    }

    sort(vi.begin(), vi.end());

    bool flag = false;
    double fst = (double) *vi.begin();
    double lst = len - (double) *(vi.end()-1);

    double mdis = (fst >= lst) ? fst : lst; 
    int tdis = 0;

    for (auto beg = vi.begin(); beg != vi.end()-1; beg++) {
	int dis = *(beg + 1) - *beg;
	if (tdis < dis) tdis = dis;
    }

    double ans = (mdis >= (double)tdis/2) ? mdis : (double)tdis/2;
    printf("%.10f\n", ans);
}
