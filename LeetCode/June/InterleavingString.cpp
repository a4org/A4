/*
 * LeetCode June #2 Interleaving String
 * Jiawei Wang
 * 2021 6.2
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace::std;

// BFS Search

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // BFS version
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if (l1 + l2 != l3) return false;
        
        vector<vector<bool>> visited(l1 + 1, vector<bool>(l2 + 1, false));
        queue<pair<int, int>> myqueue;
        myqueue.push(pair<int, int>(0, 0));  // start point
        
        while(!myqueue.empty()) {
            auto p = myqueue.front();
            myqueue.pop();
            if (p.first == l1 && p.second == l2) {  // Reach the bottom-right corner
                return true;
            }
            if (visited[p.first][p.second]) continue;
            if (p.first < l1 && s1[p.first] == s3[p.first + p.second]) {
                myqueue.push(pair<int, int>(p.first + 1, p.second));
            }
            if (p.second < l2 && s2[p.second] == s3[p.first + p.second]) {
                myqueue.push(pair<int, int>(p.first, p.second + 1));
            }
            visited[p.first][p.second] = true;
        }
        return false;
    }
};

int main() {
    Solution Sol;
    if (Sol.isInterleave("aabcc", "dbbca", "aadbbcbcac")) cout << "true" << endl;
    if (Sol.isInterleave("aabcc", "dbbca", "aadbbbaccc")) cout << "true" << endl;
    if (Sol.isInterleave("", "", "")) cout << "true" << endl;
    return 0;
}




// Analysis
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

*/















