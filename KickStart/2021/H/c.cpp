#include <iostream>
#include <string>
#include <stdio.h>
#include <limits.h>

using namespace::std;

int main() {
    int times;
    cin >> times;

    for (int i = 1; i <= times; i++) {
	int size;
	int afterSize = -1;
	string s;

	cin >> size;

	string curr;
	cin >> curr;

	string new_curr;
	while (size != afterSize) {
	    size = curr.size();
	    new_curr = "";
	    for (int j = 1; j < size; j++) {
		if (curr[j] <= curr[j-1] || curr[j] - curr[j-1] > 1) {
		    new_curr += curr[j-1];
		    if (j == size-1) curr += curr[j];
		} else {
		    // can substitute
		    if (curr[j] == '9') curr += '0';
		    else new_curr += curr[j] + 1;
		}
	    }
	    afterSize = new_curr.size();
	    curr = new_curr;
	}
	cout << "Case #" << i << ": " << curr << endl;
    }

}

