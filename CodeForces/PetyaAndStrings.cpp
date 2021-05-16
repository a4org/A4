/*
 * 112A Petya and Strings
 * Jiawei Wang
 * 16 May 2021
 */

#include <iostream>
#include <string>

using namespace::std;

/*
 * ASCII:
 * 65 - 90:  A - Z
 * 97 - 122: a - z
 */

int main() {
    string strings1;
    string strings2;

    getline(cin, strings1);
    getline(cin, strings2);

    int length12 = strings1.length();

    for (int i=0; i < length12; i++) {

	char cs1 = *strings1.begin();
	char cs2 = *strings2.begin();

	int is1 = (int) cs1;
	int is2 = (int) cs2;

	int div1 = is1 - 95;
	int div2 = is2 - 95;
	
	if (div1 > 0 && div2 < 0) is2 += 32;
	else if (div1 < 0 && div2 > 0) is1 += 32;

	if (is1 > is2) cout << 1;
	else if(is1 < is2) cout << -1;
	else {
	    strings1.erase(strings1.begin());
	    strings2.erase(strings2.begin());
	    if (strings1.length() == 0) break;

	    continue;
	}
	return 0;
    }
    cout << 0;
}
