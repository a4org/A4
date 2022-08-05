/*
 * 69A Yong Physicist
 * Jiawei Wang
 * 19 May 2021
 */

#include <iostream>

using namespace::std;

int main() {
    int num;
    cin >> num;

    int X = 0, Y = 0, Z = 0;
    int x, y ,z;

    for (int i = 0; i < num; i++) {
	cin >> x >> y >> z;
	X += x; Y += y; Z += z;
    }

    if (X == 0 && Y == 0 && Z == 0) cout << "YES";
    else cout << "NO";

    return 0;
}
