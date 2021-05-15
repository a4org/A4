/*
 * 158A Next Round
 * Jiawei Wang
 * 15 May 2021
 */

#include <iostream>

using namespace std;

int main() {
    int n, k;
    // By default, leading whitespace (carriage returns, tabs, spaces) is ignored by cin.
    cin >> n >> k;

    int a;
    for (int i = 0; i < k; ++i) {
        cin >> a;
        if (a == 0) {
            cout << i << endl;
            return 0;
        }
    }

    int b;
    for (int i = k; i < n; ++i) {
        cin >> b;
        if (b != a) {
            cout << i << endl;
            return 0;
        }
    }

    cout << n << endl;
    return 0;
}
