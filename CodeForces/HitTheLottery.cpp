/*
 * 996A Hit the Lottery
 * Jiawei Wang
 * 5 June 2021
 */

#include <iostream>
#include <vector>

using namespace::std;

long long int money, ans;
int main() {
    cin >> money;
    vector<int> denomintations = {100, 20, 10, 5, 1};

    for (int i : denomintations) {
	long long int divide = money / i, remain;
	if (divide) {
	    remain = money % i;
	    ans += divide;
	    money = remain;
	}
    }
    cout << ans << endl;

    return 0;
}
