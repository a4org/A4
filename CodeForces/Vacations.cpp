/*
 * 698A Vacations
 * Jiawei Wang
 * 5 June 2021
 */

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace::std;

template<typename T>inline void read(T &a){char c=getchar();T x=0,f=1;while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();}a=f*x;}

int num, a[100],  dp[100][3];
// dp[days][0] is rest, dp[day][1] is contest, dp[day][2] is gym


int main() {
    cin >> num;
    for (int t = 0; t < num; t++) {
	cin >> a[t];
    }
    
    // Initialize dp array to infinity
    for (int i = 0; i < num; i++)  {
	dp[i][0] = dp[i][1] = dp[i][2] = 1000;
    }

    dp[0][0] = 1;

    // see if we can do a contest on day 0
    if (a[0] == 1 || a[0] == 3) dp[0][1] = 0;
    
    // see if we can go to the gym on day 0
    if (a[0] == 2 || a[0] == 3) dp[0][2] = 0;

    for (int i = 1; i < num; i++) {
	// We can always rest
	dp[i][0] = 1 + min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]));

	// see if we can do a contest
	if (a[i] == 1 || a[i] == 3) {
	    // The previous day we could have rested or gone to the gym
	    dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
	}

	// see if we can go to the gym
	if (a[i] == 2 || a[i] == 3) {
	    // The previous day we could have rested or done a contest
	    dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
	}
    }

    cout << min(dp[num-1][0], min(dp[num-1][1], dp[num-1][2])) << endl;

    return 0;
}
