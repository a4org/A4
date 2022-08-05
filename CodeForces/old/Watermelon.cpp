/*
 * 4A Watermelon
 * Jiawei Wang
 * 15 May 2021
 */


#include <iostream>

using namespace::std;

int main() {
    int w;
    cin >> w;

    if (w % 2 == 0 && w != 2) cout << "YES";

    else cout << "NO" << endl;

    return 0; // Cannot return -1, that will cause runtime error
}

