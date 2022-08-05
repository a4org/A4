/*
 * 266A Stones on the Table
 * Jiawei Wang
 * 18 May 2021
 */

#include <iostream>
#include <vector>

using namespace::std;

int main() {
    int num;
    string stones;
    int ans;
    cin >> num;
    cin.ignore();

    getline(cin, stones);
    char ncs = stones[0]; // now focus stone
    for (int i = 1; i < num; i++) {
	char cs = stones[i];
	if (ncs == cs) ans++;
	else  ncs = cs;
    }

    cout << ans << endl;
    return 0;
}
