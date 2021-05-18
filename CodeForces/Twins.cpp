/*
 * 160A Twins
 * Jiawei Wang
 * 18 May 2021
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace::std;

int main() {
    int num;
    cin >> num;

    vector<int> coins;
    int ans = 0;

    for (int i = 0; i < num; i++) {
	int c;
	cin >> c;
	coins.push_back(c);
    }
    
    int sum = 0;
    for (int i : coins) sum+=i;
    int half = ceil(sum / 2);
    int total = 0;

    sort(coins.begin(), coins.end());

    vector<int>::const_reverse_iterator  vrb = coins.crbegin();
    vector<int>::const_reverse_iterator  vre = coins.crend();
    
    for (; vrb != vre; vrb++) {
	total += *vrb;
	ans++;
	if (total > half) {
	    break;
	}
    }

    cout << ans << endl;

    return 0;

}
