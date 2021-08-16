/*
 * LeetCode 1187 Make Array Strictly Increasing
 * Hard
 * Jiawei Wang
 * 2021 8.16
 */

#include <vector>
#include <set>

using namespace::std;
const int MAX = 2005;
const int INF = 1e9 + 5;
int dp[MAX][MAX];


class Solution {
public:
    // #1 DP (TLE)
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
	dp[0][(int)arr2.size()] = 0; // not changing the first element (at this time) (from l to r) (total changes is 0)
	for (int v = 0; v < (int) arr2.size(); ++v) {
	    dp[0][v] = 1; // changing the first element
	}
	for (int i = 1; i < (int)arr1.size(); ++i) {
	    for (int v = 0; v <= (int) arr2.size(); ++v) {
		dp[i][v] = INF;
	    }
	    for (int v0 = 0; v0 <= (int) arr2.size(); ++v0) {
		for (int v1 = 0; v1 <= (int) arr2.size(); ++v1) {
		    int value0 = (v0 == (int) arr2.size() ? arr1[i-1] : arr2[v0]);
		    int value1 = (v1 == (int) arr2.size() ? arr1[i] : arr2[v1]);
		    if (value0 < value1) {
			dp[i][v1] = min(dp[i][v1], dp[i-1][v0]
				+ (v1 == (int)arr2.size()?0:1));
		    }
		}
	    }

	}
	int answer = INF;
	for (int v = 0; v <= (int) arr2.size(); ++v) {
	    answer = min(answer, dp[(int)arr1.size()-1][v]);
	}
	if (answer == INF) return -1;

	return answer;
    }
    
    // #2 DP
    int makeArrayIncreasing2(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        if (n == 1) return 0;
        set<int> st(arr2.begin(), arr2.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        dp[0][0] = INT_MIN;
        for (int j = 1; j <= n; ++j) {
            for (int i = 0; i <= j; ++i) {
                if (arr1[j - 1] > dp[i][j - 1]) {
                    dp[i][j] = arr1[j - 1];
                }
                if (i > 0) {
                    auto it = st.upper_bound(dp[i - 1][j - 1]);
                    if (it != st.end()) dp[i][j] = min(dp[i][j], *it);
                }  
                if (j == n && dp[i][j] != INT_MAX) return i;
            }
        }
        return -1;
    }
};
