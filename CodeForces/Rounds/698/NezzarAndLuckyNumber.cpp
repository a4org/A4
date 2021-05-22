#include <iostream>

template<typename T>inline void read(T &a){char c=getchar();T x=0,f=1;while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();}a=f*x;}
using namespace::std;

int main() {
    int num;
    cin >> num;

    while (num--) {
	int times, d, q;
	read(times); read(d);
	while (times--) {
	    bool ans = true;
	    read(q);
	    if (q >= 10*d) {
		cout << "YES" << endl;
		continue;
	    } else if (q % 10 == d || q / 10 == d) { 
		cout << "YES" << endl;
		continue;
	    } else {
		for (int i = 1; i <= 10; i++) {
		    if (i * d > q) break;
		    int a = i * d % 10;
		    int b = q % 10;

		    if (a == b) {
			cout << "YES" << endl;
			ans = false;
			break;
		    }
		}
	    }
	    if (ans) {
		cout << "NO" << endl;
	    }
	}
    }
}
