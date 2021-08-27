/*
 * LeetCode 264 Ugly Number II
 * Medium
 * Jiawei Wang
 * 2021 6.7
 */


/* Revision
 * $1 2021.8.27
 */
#include <iostream>
#include <set>
#include <vector>

using namespace::std;

// #1 BFS and Brute Force
/*

   Back to its definition --> Ugly Number means that prime factore are limited to 2, 3 and 5.
   Which means that --> all Ugly Number must be obtained from other Ugly Number

   find all Ugly Number


 */

// #2 Dynamic Programming
/*
  
   In #1 you can see that we do much "useless" calculations (like exceed the limits when x5).

   So we use dp, giving each Ugly Number 3 chances -- x2(a), x3(b) and x5(c)
   these 3 numbers can help us find the minimum number each time -- no sorting needed! 

   The time complexity is O(n)


*/

class Solution {
public:
    // #1 BFS
    int nthUglyNumber(int n) {
	// find all Ugly Numbers
        vector<int> nums;
        for (long a = 1; a <= INT_MAX; a *= 2)
            for (long b = a; b <= INT_MAX; b *= 3)
                for (long c = b; c <= INT_MAX; c *= 5)
		    // 2^j * 3^k * 5^l
                    nums.push_back(c);

        std::sort(nums.begin(), nums.end());        

        return nums[n - 1];
    }

    // #2 DP
    int nthUglyNumber2(int n) {
	vector<long>vl({1});
	int a=0, b=0, c=0;
	for (int i=0; i < n-1; i++) {

	    // always find the current minimum ugly number
	    // by using current ugly numbers vector vl * {2, 3, 5}
	    int num = min(min(vl[a]*2, vl[b]*3), vl[c]*5);

	    if (vl[a]*2 == num) a++;
	    if (vl[b]*3 == num) b++;
	    if (vl[c]*5 == num) c++;
	    vl.push_back(num);
	}
	return vl[n-1];
    }
};
