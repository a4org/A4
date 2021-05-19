/*
 * 58A ChatRoom
 * Jiawei Wang
 * 19 May 2021
 */

#include <iostream>
#include <string>

using namespace::std;

int main() {
    string s;
    cin >> s;

    string hello = "hello";

    int index = 0; // to find
    for (char c : s) if (c == hello[index]) index++;
    if (index == 5) cout << "YES";
    else cout << "NO";
}
