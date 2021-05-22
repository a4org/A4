#include <iostream>

using namespace::std;
template<typename T>inline void read(T &a){char c=getchar();T x=0,f=1;while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();}a=f*x;}


int main() {
    int num;
    cin >> num;

    while (num--) {
	int times;
	cin >> times;

	int prv;
	int maximum = 0;
	int cmax = 0; // current length
	read(prv);
	times = times-1;
	while (times--) {
	    int curr;
	    read(curr);
	    if (curr == prv) {
		cmax++;
	    } else {
		prv = curr;
		cmax = 0;
	    }
	    if (maximum < cmax) maximum = cmax;
	}
	cout << maximum+1 << endl;
    }
}
