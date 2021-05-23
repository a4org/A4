/*
 * 474B Worms
 * Jiawei Wang
 * 23 May 2021
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
typedef long int li;
typedef std::vector<li>::iterator vlii;



template<typename T>inline void read(T &a){char c=getchar();T x=0,f=1;while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();}a=f*x;}

using namespace::std;

vector<long int> vli;


int main() {
    li num, temp;
    cin >> num;
    while (num--) {
	read(temp);
	vli.push_back(temp);
    }
    for (auto b = vli.begin()+1; b != vli.end(); b++) *b += *(b-1);

    vli.shrink_to_fit();

    cin >> num;
    vlii group;
    while(num--) {
	li target, pile = 0; 
	read(target);
	// binary search
	group = lower_bound(vli.begin(), vli.end(), target);
	cout << group - vli.begin()+1 << endl;
    }
}
