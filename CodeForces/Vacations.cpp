/*
 * 698A Vacations
 * Jiawei Wang
 * 5 June 2021
 */

#include <iostream>
#include <stdio.h>

using namespace::std;

template<typename T>inline void read(T &a){char c=getchar();T x=0,f=1;while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();}a=f*x;}

void test_case() {

}

int main() {
    int num;
    cin >> num;
    for (int t = 1; t <= num; t++) {
	printf("Case #%d:", t);
	test_case();
    }
    return 0;
}
