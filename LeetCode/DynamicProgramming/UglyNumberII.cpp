/*
 * LeetCode 264 Ugly Number II
 * Medium
 * Jiawei Wang
 * 2021 6.7
 */

#include <iostream>
#include <set>
#include <vector>

using namespace::std;

// #1 BFS and Brute Force
/*

   Back to its definition --> Ugly Number means that prime factore are limited to 2, 3 and 5.
   Which means that --> all Ugly Number must be obtained from other Ugly Number

   Since we need to use set to sort all ugly numbers, the time complexity is O(nlogn)

 */

// #2 Dynamic Programming
/*
  
   In #1, we use set to sort n elements, which costs much time. 
   and you can see that we do much "useless" calculations (like exceed the limits when x5).

   So we use dp, giving each Ugly Number 3 chances -- x2(a), x3(b) and x5(c)
   these 3 numbers can help us find the minimum number each time -- no sorting needed! 

   The time complexity is O(n)


*/

class Solution {
public:
    // #1 BFS
    int nthUglyNumber1(int n) {
	set<long>Set({1});
	long num;
	for (int i=0; i<n; i++) {
	    num = *Set.begin();
	    Set.insert(num*2);
	    Set.insert(num*3);
	    Set.insert(num*5);
	}
	return num;
    }

    // #2 DP
    int nthUglyNumber2(int n) {
	vector<long>vl({1});
	int a=0, b=0, c=0;
	for (int i=0; i < n-1; i++) {
	    int num = min(min(vl[a]*2, vl[b]*3), vl[c]*5);
	    if (vl[a]*2 == num) a++;
	    if (vl[b]*3 == num) b++;
	    if (vl[c]*5 == num) c++;
	    vl.push_back(num);
	}
	return vl[n-1];
    }
};
