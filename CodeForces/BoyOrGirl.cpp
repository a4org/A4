/*
 * 236A Boy or Girl
 * Jiawei Wang
 * 17 May 2021
 */

#include <iostream>
#include <string>
#include <vector>

using namespace::std;

int main() {
    string name;
    getline(cin, name);
    vector<int> charVec (26, 0);
    int ans = 0;

    
    for (char c : name) charVec[(int)c - 97] = 1;
    for (int i : charVec) if (i) ans++;

    if (ans % 2) cout << "IGNORE HIM!" << endl;
    else cout << "CHAT WITH HER!" << endl;

    return 0;
}
