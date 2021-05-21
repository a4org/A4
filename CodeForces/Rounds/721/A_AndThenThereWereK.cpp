#include <iostream>

using namespace::std;

int main() {
    int num;
    cin >> num;

    while(num--) {
	long long n;
	cin >> n;
	long long ans = n;
	for (int i = n-1; i >= 0; i--) {
	    ans = ans & i;
	    if (!ans) {
		cout << i << endl;
		break;
	    }
	}
    }
}
