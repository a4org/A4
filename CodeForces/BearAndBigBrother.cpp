/*
 * 791A Bear and Big Brother
 * Jiawei Wang
 * 18 May 2021
 */

#include <iostream>

using namespace::std;

int main() {
    int limak, bob;
    cin >> limak >> bob;
    bool st = true;
    int ans = 0;

    while(st) {
	ans++;
	limak*=3;
	bob*=2;
	if (limak > bob) st = false;
    }
    
    cout << ans << endl;
    return 0;
}

