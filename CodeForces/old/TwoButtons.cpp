/*
 * 520B Two Buttons
 * Jiawei Wang
 * 27 May 2021
 */


// we should get the number n starting from m using the operations 
// "add 1 to the number" and "divide the number by 2 if it is even".


#include<iostream>

using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    if(m<=n ) {
	cout<< n-m <<endl;
	return 0;
    }
    int ans=0;
    while(n < m) {
        if( m%2 ) m++; else m/=2;
	ans++;
    }
    ans+= ( n-m );
    cout<<ans<<endl;
    return 0;
}
 
