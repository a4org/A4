#include <iostream>
#include <string>

using namespace::std;

int main() {
    int num;
    cin >> num;

    while (num--) {
	int len;
	cin >> len;

	string s;
	cin >> s;
	int zero = 0;
	for (char c : s) {
	    if (c == '0') {
		zero++;
	    }
	}

	if (zero % 2 == 0) {
	    if (zero % 4 == 0) {
		cout << "DRAW" << endl;
		break;
	    }
	    cout << "BOB" << endl;
	}

	if (zero % 2 == 1) {
	    if (zero % 4 == 1) {
		cout << "BOB" << endl;
		break;
	    }
	    cout << "ALICE" << endl;
	}

	if (zero == 1) cout << "BOB";
    }
}

