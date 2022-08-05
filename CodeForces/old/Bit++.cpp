/*
 * 282A Bit++
 * Jiawei Wang
 * 16 May 2021
 */

#include <iostream>
#include <string>

using namespace::std;

int main() {
    int times = 0;
    int X = 0; // answer
    cin >> times;
    cin.ignore(); // ignore the '\n' 
    for (int i=0; i<times; i++) {
	string command;
	char sc = 'u'; // unused

	getline(cin, command);
	for (char c : command) {
	    if (sc != 'u') {
		if (sc == c) {
		    if (c == '+') {
			X++;
			goto cnt;
		    } else if(c == '-') {
			X--;
			goto cnt;
		    } else {
			cout << "Invalid Syntax(1)" << endl;
			return -1;
		    }
		}
		else {
		    cout << "Invalid Syntax(2)" << endl;
		    return -1;
		}
	    }
	    if (c == '+' || c == '-') {
	        sc = c; // store c
	    }
	}
cnt:;
    }
    cout << X << endl;
    return 0;
}
