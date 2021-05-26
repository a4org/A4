/*
 * Given Length and Sum of Digits...
 * Jiawei Wang
 * 26 May 2021
 */

#include <iostream>
#include <stdio.h>
#include <string>

using namespace::std;

template<typename T>inline void read(T &a){char c=getchar();T x=0,f=1;while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();}a=f*x;}

// 0 - 9 (48 - 57)

int main() {
    int m, s;
    read(m); read(s);

    if (m == 1) {
	if (s < 10) {
	    cout << s << " " << s << endl;
	    return 0;
	} else  {
	    cout << "-1 -1" << endl;
	    return 0;
	}
    }

    string minans = "1";
    int t = m-1; // push 0
    while (t--) {
	// find the minimum
	minans.push_back('0');
    }

    int remain = s-1;
    int n = 1;
    for (; n <= m; n++) {
	char &cdigit = minans[m-n]; // mindigit
	if (remain - 9 >= 0 && n != m) {
	    cdigit = '9';
	    remain -= 9;
	    continue;
	} else {
	// greedy here
	    while (remain > 0 && (int)cdigit < 57) {
		remain -= 1;
		cdigit += 1;
	    }
	}
    }

    if (remain) {
	printf("%d %d", -1, -1);
    } else {
	string maxans = "";
	if (*(minans.end()-1) == '0') { // the last digit is zero
	    printf("%s %s", minans.c_str(), minans.c_str());
	    return 0;
	} 

	for (auto it = minans.end()-1; it >= minans.begin(); it--) {
	    maxans.push_back(*it);
	}
	auto itend = maxans.end() - 1;
	auto itd = maxans.end() - 2;
	
	if (*itend == '1') {
	    *itend = '0';
	    while ((int)*itd < 57 && itd != maxans.begin()) {
		itd -= 1;
	    }
	    if (itd == maxans.begin() && *itd < 57) {
		*(itd) += 1;
	    } else {
		*(itd+1) += 1;
	    }
	}


	printf("%s %s", minans.c_str(), maxans.c_str());
    }

}
