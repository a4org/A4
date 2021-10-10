/* 
 * Errichto Tutorial printBit
 * https://www.youtube.com/watch?v=xXKL9YBWgCY
 * 2021.10.10 
 * Jiawei Wamng
 */

#include <iostream>

using namespace::std;

void printBit(int num) {
    for (int i = 31; i >= 0; i--) {
	if (num & (1 << i)) cout << 1;
	else cout << 0;
    }
    cout << endl;
}

int main() {
    printBit(4);
    printBit(18);
    printBit(128);
}
