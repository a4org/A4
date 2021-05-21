#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
#include<iostream>
#include<cmath>
#include<map>
#define debug(x) cout<<#x<<":"<<x<<endl;
#define dl(x) printf("%lld\n",x);
#define di(x) printf("%d\n",x);
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll INF= 1e18+7;
const ll maxn = 1e6+700;
const ll mod= 1000000007;
const double eps = 1e-9;
const double PI = acos(-1);
template<typename T>inline void read(T &a){char c=getchar();T x=0,f=1;while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();}a=f*x;}

ll n,m,p;
map<int,int>A,B;
map<pair<int,int>,int>C;
ll a[maxn],b[maxn];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		ll att,bt;
		read(att);read(bt);read(n);
		A.clear();B.clear();C.clear();
		for(int i=1;i<=n;i++) read(a[i]);
		for(int i=1;i<=n;i++) read(b[i]);
		ll ans = 0;
		for(int i=1;i<=n;i++){	
			ans += (i-1)*1ll - (A[a[i]]+B[b[i]]-C[{a[i],b[i]}]);
			A[a[i]]++;B[b[i]]++;
			C[{a[i],b[i]}]++;
			// debug(ans);
		}
	    dl(ans);
	}
 	return 0;
    
}

template<typename T>inline void readc(T &a) {
    char c = getchar();
    T x = 0, f = 1;
    while(!isdigit(c)) {
	if (c == '-') f = -1;
	c = getchar();
    }
    while(isdigit(c)) {
	x = (x<<1) + (x<<3) + c - '0'; // x = x*2 + x*2^3 + c(ascii) - 48
	c = getchar();
    }
    a = f*x;
}
