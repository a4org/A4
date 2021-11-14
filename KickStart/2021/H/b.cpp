#include <iostream>
#include <string>
#include <stdio.h>
#include <limits.h>

using namespace::std;

int main() {
    // Brute Force
    int times;
    cin >> times;

    for (int i = 1; i <= times; i++) {
	int ret = 0;
	int len;
	string s;
	cin >> len;
	cin >> s;


	char p = ' ';
	for (char c : s) {
	    if (c == p) {
		continue; // just paint it together
	    }
	    switch(c) {
		case 'R': 
		    if (p == 'O' || p == 'P' || p == 'A') break;
		    else ret++; break;
		case 'Y': 
		    if (p == 'O' || p == 'G' || p == 'A') break;
		    else ret++; break;
		case 'B':
		    if (p == 'P' || p == 'G' || p == 'A') break;
		    else ret++; break;
		case 'O':
		    if (p == 'R' || p == 'Y' || p == 'P' || p == 'G') ret++; // only need to add 1
		    else if (p == 'A') break;
		    else ret+=2; break;
		case 'P':
		    if (p == 'R' || p == 'B' || p == 'G' || p == 'O') ret++;
		    else if (p == 'A') break;
		    else ret+=2; break;
		case 'G':
		    if (p == 'Y' || p == 'B' || p == 'P' || p == 'O') ret++;
		    else if (p == 'A') break;
		    else ret+=2; break;
		case 'A':
		    if (p == 'G' || p == 'O' || p == 'P') ret++;
		    else if (p == 'R' || p == 'Y' || p == 'B') ret+=2;
		    else ret+=3; break;
		case 'U':
		    // do not print
		    break;
	    }
	    p = c;
	}
	printf("Case #%i: %i\n", i, ret);
    }
}

// R Y B

// R + Y = O
// R + B = P
// Y + B = G
// R + Y + B = A
