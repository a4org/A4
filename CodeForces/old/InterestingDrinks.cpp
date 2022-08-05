#include <algorithm>
#include <iostream>

using namespace::std;

int main()
{
        long long int i,j,k,f,l;
        long long int n,q,count=0;

	cin >> n;
        long long int x[n];
        for(i=0;i<n;i++)
        {
	    int price;
	    cin >> price;
	    x[i] = price;
        }

	cin >> q;
        long long int m[q];
        for(i=0;i<q;i++)
        {
	    int money;
	    cin >> money;
	    m[i] = money;
        }

        sort(x,x+n);

        for(i=0;i<q;i++)
        {
	    cout<<upper_bound(x,x+n,m[i])-x<<"\n";
        }

        return 0;
}
