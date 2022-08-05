/*
 * 1352C K-th Not Divisible by n
 * Jiawei Wang
 * 23 May 2021
 */

#include <iostream>
#include <stdio.h>

template<typename T>inline void read(T &a){char c=getchar();T x=0,f=1;while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();}a=f*x;}

using namespace::std;


int solve() {
    long long int n, k, ans;
    long long int temp = 0, remain = 0;

    read(n); read(k);

    remain = k % (n-1); // what remain
    temp =(long long int) k / (n-1); // see how many pairs of numbers we need
    if (!remain) {
	temp-=1;
	remain = n-1;
    }
    ans = n * temp + remain;
    return ans;
}

int main() {
    int num;
    cin >> num;

    int ans;
    while (num--) {
	ans = solve();
	cout << ans << endl;
    }

}



