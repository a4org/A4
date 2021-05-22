#include <stdio.h>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
 
set<ll> s;
vll a, b;
int n;

template<typename T>inline void read(T &a){char c=getchar();T x=0,f=1;while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();}a=f*x;}

 
bool solve(){
    read(n);
    s.clear(); a.clear(); b.clear();
 
    a.assign(2 * n, 0LL);
 
    for (int i = 0; i < 2*n; i++) {
	read(a[i]);
	s.insert(a[i] / 2);
    }
    for (int i = 0; i < 2*n; i++) {
	if (a[i] & 1) return false;
    }

    if(int(s.size()) != n) return false;
    b.clear();
    for(ll v: s) b.push_back(v);
    s.clear();
    long double sm =0;
    for(int rep = n - 1; rep > -1; --rep){
        ll val = (b[rep] - sm);
        if((val % (rep + 1)) || val <= 0) return 0;
        val /= (rep + 1);
        s.insert(val);
        s.insert(-1 * val);
        sm += val;
    }
    return int(s.size()) == 2 * n;
}
 
int main()
{
    int t; read(t);
    while(t--){
        printf("%s\n", solve() ? "YES" : "NO");
    }
    return 0;
}
