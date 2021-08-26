/*
 * LeetCode 97 Interleaving String
 * Medium
 * Jiawei Wang
 * 2021 6.2
 */

/* Revision
 * $1: 2021 8.26 Jiawei Wang
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace::std;

// #1 BFS Search
/*

   s1 = aab  s2 = abc  s3 = aaabcb

   o -- a -- o -- b -- o -- c -- o
   |         |         |         |
   a         a         a         a
   |         |         |         |
   o -- a -- o -- b -- o -- c -- o
   |         |         |         |
   a         a         a         a
   |         |         |         |
   o -- a -- o -- b -- o -- c -- o
   |         |         |         | 
   b         b         b         b
   |         |         |         |
   o -- a -- o -- b -- o -- c -- o

   if we can move from the top-left corner to the bottom-right corner by go through the s3
   Then we can say s3 can be represented by interleaving s1 and s2
   like the 'x' route below:

   x -- a -- o -- b -- o -- c -- o
   |         |         |         |
   a         a         a         a
   |         |         |         |
   o -- a -- x -- b -- o -- c -- o
   |         |         |         |
   a         a         a         a
   |         |         |         |
   o -- a -- x -- b -- x -- c -- x
   |         |         |         | 
   b         b         b         b
   |         |         |         |
   o -- a -- o -- b -- o -- c -- x

   time complexity : O(mn) (go through all chessboard)

*/

// #2 DP Table
/*
 
   Basic idea: 
   Whether s1, s2 and s3 satisfy the interleaving string, 
   just depend on whether their one less character state meets the interleaving string property.

   time complexity : O(mn)
*/

class Solution {
public:
    // #1 BFS (Chess)
    bool isInterleave1(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if (l1 + l2 != l3) return false;
        
        vector<vector<bool>> visited(l1 + 1, vector<bool>(l2 + 1, false));
        queue<pair<int, int>> myqueue; // store all possible cases
        myqueue.push(pair<int, int>(0, 0));  // start point
        
        while(!myqueue.empty()) {
            auto p = myqueue.front(); // front pair
            myqueue.pop(); // pop front (The "oldest" element of the queue)
            if (p.first == l1 && p.second == l2) {  // Reach the bottom-right corner
                return true;
            }

            if (visited[p.first][p.second]) continue; // if we reached that point before 
	    // then do not need to search it again (pass) 
	    // imagin that two route came to the same point

	    // Sometimes, when s1[p.first] == s2[p.second]: two nodes (points) should be put into queue
            if (p.first < l1 && s1[p.first] == s3[p.first + p.second]) {
		// get one s1 word, move one step down
                myqueue.push(pair<int, int>(p.first + 1, p.second));
            }
            if (p.second < l2 && s2[p.second] == s3[p.first + p.second]) {
		// get one s2 word, mive one step right
                myqueue.push(pair<int, int>(p.first, p.second + 1));
            }

            visited[p.first][p.second] = true; // visited just means we can reach that point
        }
        return false;
    }

    
    // #2 DP Table
    bool isInterleave2(string s1, string s2, string s3) {
	int m = s1.size();
	int n = s2.size();

	if (m+n!=s3.size()) return false;

	auto dp = vector<vector<bool>>(m+1, vector<bool>(n+1, false));
	// check its one less character state meets the interleaving property
	// dp[i][j] means: choose the (0, i) indices of s1 and (0, j) of s2
	// whether they can form an interleaving string s3 (0, i + j)
	// Since s1.size() + s2.size() == s3.size(). We just return  dp[m][n]

	s1 = '#'+s1;
	s2 = '#'+s2;
	s3 = '#'+s3;

	dp[0][0] = 1;

	// i / j == 0
	for (int i=1; i<=m; i++) {
	    dp[i][0] = (dp[i-1][0]==true && s1[i]==s3[i]);
	}

	for (int j=1; j<=m; j++) {
	    dp[0][j] = (dp[0][j-1]==true && s1[j]==s3[j]);
	}

	for (int i=1; i<=m; i++) {
	    for (int j=1; j<=n; j++) {
		// check its one less character state meets the interleaving property
		if (s1[i]==s3[i+j] && dp[i-1][j]) 
		    dp[i][j] = true;
		else if (s2[j]==s3[i+j] && dp[i][j-1])
		    dp[i][j] = true;
	    }
	}
	return dp[m][n];
    }
};



// Test Case
int main() {
    Solution Sol;
    if (Sol.isInterleave1("aabcc", "dbbca", "aadbbcbcac")) cout << "true" << endl;
    if (Sol.isInterleave1("aabcc", "dbbca", "aadbbbaccc")) cout << "true" << endl;
    if (Sol.isInterleave1("", "", "")) cout << "true" << endl;
    if (Sol.isInterleave2("aabcc", "dbbca", "aadbbcbcac")) cout << "true" << endl;
    if (Sol.isInterleave2("aabcc", "dbbca", "aadbbbaccc")) cout << "true" << endl;
    if (Sol.isInterleave2("", "", "")) cout << "true" << endl;
    return 0;
}

