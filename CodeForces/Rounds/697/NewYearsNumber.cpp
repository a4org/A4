#include <iostream>

using namespace::std;

int main() {
    int num;
    cin >> num;

    while(num--) {
	long long int number;
	cin >> number;

	long long int divine = (int) number / 2020;
	long long int remain = number % 2020;
	if (divine >= remain && divine) cout << "YES" << endl;
	else cout << "NO" << endl;
    }
}


