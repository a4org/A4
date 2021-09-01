/*
 * LeetCode 279 Perfect Squares
 * Medium
 * Jiawei Wang
 * 2021 9.1
 */

/* #1 DP
 * Time Complexity: O(nlogn)
 * Example:
 * n = 12
 * dp[0] = 0 (dp[0])
 * dp[1] = 1 (dp[0] + 1) 
 * dp[2] = 2 (dp[1] + 1)
 * dp[3] = 3 (dp[2] + 1) 
 * dp[4] = 1 (dp[4-2*2] + 1)
 * dp[5] = 2 (dp[4] + 1)
 * dp[6] = 3 (dp[5] + 1) / (dp[6 - 2*2] + 1)
 * dp[7] = 4 (dp[6] + 1) / (dp[7 - 2*2] + 1)
 * dp[8] = 2 (dp[8 - 2*2] + 1)
 * ...
 * dp[12] = 3 (dp[12 - 2*2] + 1)
 *
 * #2 BFS (Important)
 *
 * #3 Math
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace::std;

class Solution {
public:
    // #1 DP
    int numSquares1(int n) {
	if (n <= 0) return 0;

	vector<int> dp(n+1, INT_MAX); 
	// dp[i] represents the current minimum number of perfect square numbers that sum to i
	
	dp[0] = 0;
	for (int i = 0; i <= n; i++) {
	    // all we need to do is that to keep the dp property for each different i (target)
	    // and use this propert each further steps
	    for (int q = 1; q <= sqrt(i); q++) {
		// dp --> consider every possible cases
		dp[i] = min(dp[i], dp[i-q*q]+1); // key part
		// every target number is obtained from other smaller number Plus one perfect square number
		// if we keep all previous(smaller) dp has this property, then we can easilt get the current dp[i]
		// by just looping all different cases(minus perfect square numbers)
	    }
	}
	return dp.back(); // use back() is faster that [n]
    }


    // #1.5 Faster DP (Static)
    // Time Complexity is the same as #1 DP 
    int numSquares2(int n) {
	if (n <= 0) return 0;

	static vector<int> dp({0}); // can be reused in the future tests (Only faster in LC)

	while (dp.size() <= 0) {
	    int i = dp.size();
	    int temp = INT_MAX;

	    for (int q = 1; q <= sqrt(i); q++) {
		temp = min(temp, dp[i-q*q] + 1);
	    }

	    dp.push_back(temp);
	}
	return dp[n];
    }

    // #2 BFS
    // Shortest -> BFS
    int numSquares3(int n) {
	if (n <= 0) return 0;

	vector<int> perfectSquares; // contains all perfect squre numbers which are smaller or equal to n
	vector<int> dp(n+1);  // dp[i] -> the least number of perfect squre numbers which sum to i

	for (int i = 1; i <= sqrt(n); i++) {
	    perfectSquares.push_back(i*i);
	    dp[i*i] = 1;
	}

	if (perfectSquares.back() == n) return 1;

	queue<int> searchQ;
	for (auto& i : perfectSquares) {
	    searchQ.push(i);
	}

	int ans = 1; // the root node is 0
	// BFS start (a sqrt(n) search tree)
	while (!searchQ.empty()) {
	    // Current Layer (Tree depth == ans)
	    ans++;
	    int size = searchQ.size();
	    for (int i = 0; i < size; i++) {
		// for each nodes in this layer
		int tmp = searchQ.front();
		for (auto& s : perfectSquares) {
		    // for each child node in this node
		    if (tmp + s == n) return ans; // get the target (BFS shortest path)
		    else if ((tmp + s < n) && (dp[tmp + s] == 0)) {
			// if dp[tmp + s] means this node we've already visited before or in this layer
			dp[tmp+s] = ans;
			searchQ.push(tmp+s);
		    }
		    else if (tmp + s > n) {
			// we don't need to consider the nodes which are greater than n
			break;
		    }
		}
		searchQ.pop();
	    }
	}
	return 0;
    }

    // #3 Math
    // Based on Lagrange's Four Square theorem, there 
    // are only 4 possible results: 1, 2, 3, 4.
    int numSquares4(int n) {  
        // If n is a perfect square, return 1.
        if(is_square(n)) {
            return 1;  
        }
        
        // The result is 4 if and only if n can be written in the 
        // form of 4^k*(8*m + 7). Please refer to 
        // Legendre's three-square theorem.
        while ((n & 3) == 0) { // n%4 == 0  
            n >>= 2;  
        }
        if ((n & 7) == 7) { // n%8 == 7
            return 4;
        }
        
        // Check whether 2 is the result.
        int sqrt_n = (int)(sqrt(n)); 
        for(int i = 1; i <= sqrt_n; i++) {  
            if (is_square(n - i*i)) {
                return 2;  
            }
        }  
        
        return 3;  
    }  
private:  
    int is_square(int n) {  
        int sqrt_n = (int)(sqrt(n));  
        return (sqrt_n*sqrt_n == n);  
    }
};
