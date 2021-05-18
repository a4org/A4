/*
 * 546A Soldier and Bananas
 * Jiawei Wang
 * 18 May 2021
 */

#include <iostream>
#include <string>

using namespace::std;

int main() {
    int p, d, n;
    cin >> p >> d >> n;

    int ans = 0;
    for (int i = 1; i <= n; i++) ans += i;
    ans = d - p * ans;
    if (ans < 0) ans -= 2*ans;
    else ans = 0;

    cout << ans << endl;

    return 0;

}

