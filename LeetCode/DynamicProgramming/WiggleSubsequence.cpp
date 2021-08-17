/*
 * LeetCode 376 Wiggle Subsequence
 * Medium
 * Jiawei Wang
 * 2021 8.17
 */

#include <vector>

using namespace::std;

class Solution {
public:
    // #1 O(n^2) dp
    int wiggleMaxLength(vector<int>& nums) {
	// two status
	const int n = nums.size();
	vector<vector<int>> dp(n, vector<int>(2));
	// dp[i][0] --> smaller length
	// dp[i][1] --> larger length
	int answer = 0;

	for (int i = 0; i < n; ++i) {
	    dp[i][0] = dp[i][1] = 1; // at current index minimum WM length is 0
	    for (int j = 0; j < i; ++j) {
		// for each element before i
		if (nums[j] < nums[i]) {
		    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
		}

		if (nums[j] > nums[i]) {
		    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
		}
	    }
	    answer = max({answer, dp[i][0], dp[i][1]});
	}
	return answer;
    }


    // #2 O(n) DP
    int wiggleMaxLength2(vector<int>& nums) {
        int size = nums.size();
        
        if (size == 0) {
            return 0;
        }
        
        /** up[i] is the length of a longest wiggle subsequence of {nums[0],...,nums[i]}, with a
            positive difference between its last two numbers. This subsequence may or may not
            include nums[i] and there may be several such subsequences (of the same length).
            We call this a subsequence of type U.
         */
        vector<int> up(size, 0);
        /** down[i] is the length of a longest wiggle subsequence of {nums[0],...,nums[i]}, with a
            negative difference between its last two numbers. This subsequence may or may not
            include nums[i] and there may be several such subsequences (of the same length).
            We call this a subsequence of type D.
         */
        vector<int> down(size, 0);
        
        // At i=0, there is only one number and we can use it as a subsequence, i.e up[0]=down[0]=1
        up[0] = 1;
        down[0] = 1;
        for(int i=1; i<size; ++i){
            
            if (nums[i] > nums[i-1]) {
                /** If nums[i] > nums[i-1], then we can use nums[i] to make a longer subsequence of type U
                    Proof: We consider a subsequence of type D in {0,...,i-1} (its length is down[i-1]).
                    Let N be the last number of this subsequence.
                    - If nums[i] > N, then we can add nums[i] to the subsequence and it gives us a longer
                    valid subsequence of type U.
                    - If nums[i] <= N, then:
                    (1) N cannot be nums[i-1], because nums[i-1] < nums[i] <= N i.e. nums[i-1] < N
                    (2) We can replace N with nums[i-1] (we still have a valid
                    subsequence of type D since N >= nums[i] > nums[i-1] i.e. N > nums[i-1]),
                    and then add nums[i] to the subsequence, and we have a longer subsequence of type U.
                    Therefore up[i] = down[i-1] + 1
                    
                    There is no gain in using nums[i] to make a longer subsequence of type D.
                    Proof: Let N be the last number of a subsequence of type U
                    in {0,...,i-1}.
                    Assume we can use nums[i] to make a longer subsequence of type D. Then:
                    (1) N cannot be nums[i-1], otherwise we would not be able to use nums[i]
                    to make a longer subsequence of type D as nums[i] > nums[i-1]
                    (2) Necessarily nums[i] < N, and therefore nums[i-1] < N since nums[i-1] < nums[i].
                    But this means that we could have used nums[i-1] already to make a longer
                    subsequence of type D.
                    So even if we can use nums[i], there is no gain in using it, so we keep the old value of
                    down (down[i] = down[i-1])
                */
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            }
            else if (nums[i] < nums[i-1]) {
                /** The reasoning is similar if nums[i] < nums[i-1] */
                down[i] = up[i-1] + 1;
                up[i] = up[i-1];
            }
            else {
                /** if nums[i] == nums[i-1], we cannot do anything more than what we did with
                     nums[i-1] so we just keep the old values of up and down
                */
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }
        return max(up[size-1], down[size-1]);
    }

};
