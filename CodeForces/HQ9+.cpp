/* 
 * 133A HQ9+.cpp
 * Jiawei Wang
 * 18 May 2021
 */

#include <iostream>
#include <string>

using namespace::std;

int main() {
    string command;
    cin >> command;

    for (char c : command) {
	if ((int)c == 57) {
	    cout << "YES" << endl;
	    return 0;
	} else if ((int)c == 72) {
	    cout << "YES" << endl;
	    return 0;
	} else if ((int)c == 81) {
	    cout << "YES" << endl;
	    return 0;
	} 
    }
    cout << "NO" << endl;
    return 0;
}

