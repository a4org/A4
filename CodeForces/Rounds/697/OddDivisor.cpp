#include <iostream>


using namespace::std;

int main() {
    int num;
    cin >> num;

    while (num--) {
	long long int li;
	cin >> li;

	if (li % 2) {
	    // odd
	    if (li == 1) {
		cout << "NO" << endl;
		continue;
	    }
	    cout << "YES" << endl;
	} else {
	    // even
	    while (li != 1) {
		li = li / 2;
		if (li % 2 && li != 1) {
		    cout << "YES" << endl;
		    break;
		} 
	    }
	    if (li == 1) cout << "NO" << endl;
	}

    }

}
