/*
 * 698A Vacations
 * Jiawei Wang
 * 5 June 2021
 *
 * revision #1 on 23 July 2021
 * dp[days][0]: minimum days rested up to the current day if we rest on the current day
 * dp[days][1]: minimum days rested up to the current day if we choose contest on the current day
 * dp[days][2]: minimum days rested up to the current day if we choose gym on the current day
 *
 *
 * example: a-> 1 3 2 0
 * ----------------------------------
 * | (days) | (0) | (1) | (2) | (3) |
 * |   0    |  1  |  1  |  1  |  2  |
 * |   1    |  0  |  1  | INF | INF |
 * |   2    | INF |  0  |  1  | INF |
 * ----------------------------------
 * |   a    |  1  |  3  |  2  |  0  |
 *
 *
 * revision #2 on 39 Aug 2021
 * DP -> Consider all possibilities each iteration
 *
 */

#include <iostream>
#include <algorithm>

using namespace::std;

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
    if (a[0] == 1 || a[0] == 3) dp[0][1] = 0; // contest open
    
    // see if we can go to the gym on day 0
    if (a[0] == 2 || a[0] == 3) dp[0][2] = 0; // gym open

    for (int i = 1; i < num; i++) {
	// We can always rest
	dp[i][0] = 1 + min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]));

	// see if we can do a contest
	if (a[i] == 1 || a[i] == 3) {
	    // we can do a contest
	    // The previous day we could have rested or gone to the gym
	    dp[i][1] = min(dp[i-1][0], dp[i-1][2]); // choose contest
	}

	// see if we can go to the gym
	if (a[i] == 2 || a[i] == 3) {
	    // we can go to the gym
	    // The previous day we could have rested or done a contest
	    dp[i][2] = min(dp[i-1][0], dp[i-1][1]); // choose gym 
	}
    }

    cout << min(dp[num-1][0], min(dp[num-1][1], dp[num-1][2])) << endl;

    return 0;
}
