#include <iostream>
#include <stdio.h>

template<typename T>inline void read(T &a){char c=getchar();T x=0,f=1;while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();}a=f*x;}

using namespace::std;

int solve() {
    int times;
    read(times);

    int mini = 101;
    int ng = 0; // num of distinct
    for (int i = 0; i < times; i++) {
	int temp;
	read(temp);
	if (temp < mini) {
	    ng = 0;
	    mini = temp;
	}
	if (temp == mini) ng++;
    }

    return times - ng;
}

int main() {
    int num;
    cin >> num;
    
    while(num--) {
	cout << solve() << endl;
    }
}



