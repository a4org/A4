/*
 * 4C Registration system
 * Jiawei Wang
 * 25 May 2021
 */

#include <iostream>
#include <map>
#include <string>

using namespace::std;

map<string, long> database;
string solve() {
    string temp;
    cin >> temp;
    if (!database[temp]) {
	database[temp]++;
	return "OK";
    } else {
	string lstr = to_string(database[temp]);
	database[temp]++;
	return temp + lstr;
    }
}

int main() {
    long num;
    cin >> num;

    while(num--) {
	cout << solve() << endl;

    }

}
