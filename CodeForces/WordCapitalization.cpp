 /*
 * 281A Word Capitalization
 * Jiawei Wang
 * 16 May 2021
 */

#include <iostream>
#include <string>

using namespace::std;

int main() {
    string s;
    cin >> s;

    s[0] = toupper(s[0]);
    cout << s;

    return 0;
}
