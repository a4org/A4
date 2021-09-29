/*
 * CodeForces 698A Vacations
 * Shuo Feng
 * 2021.8.30
 * Last edited at 2021.9.30
 */

/*
 * Solution: Dp
 *   Each time renew the situation before the day as the basis to judge the next day.
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> dp  (101);     // The minimum day that can rest till day i .
vector<int> situ(101, 0);  // Situation of day i.

int main() {
    int days;   // Vacation days;
    cin >> days;

    for (int i = 1; i <= days; ++i) {
        cin >> situ[i];
    }
    dp[0] = 0;
    int situ_before = 0; // Situation before the day, default rest before vacation.

    for (int i = 1; i <= days; ++i) {
        
        // ◆(1). The gym is closed and the contest is not carried out --> can only rest.
        if (situ[i] == 0) {
            dp[i] = dp[i - 1] + 1; // On the basic of day 'i - 1', add rest day.
            situ_before = 0; // Upadte situation_before.
        }
        else if (situ[i] == 1 || situ[i] == 2) {
            
            // ◆(2). Only gym is open or only carried the contest, two cases:  1. do the same activity --> rest.
            //                                                                2. else                 --> activity.
            if (situ[i] == situ_before) {
                dp[i] = dp[i - 1] + 1;
                situ_before = 0;
            }
            else if (situ[i] != situ_before) {
                dp[i] = dp[i - 1];
                situ_before = situ[i];
            }
        }
        
        // ◆(3). The gym is open and the contest is carried out --> can always find something to do.
        //      Judge of the situation (explame about line 59 'situ_before = situ[i] - situ_before;'):
        //         1. If situation before is " 2 ", then write the contest (situation 1 ).
        //         2. If situation before is " 1 ", then do sport          (situation 2 ).
        //         3. If situation before is " 0 ", write the contest, do sport, rest are possible (situation 3 ).
        else if (situ[i] == 3) {
            dp[i] = dp[i - 1];
            situ_before = situ[i] - situ_before;
        }
    }
    cout << dp[days] << endl;
    return 0;
}
