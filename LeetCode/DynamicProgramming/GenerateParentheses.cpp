/*
 * LeetCode 22 Generate Parentheses
 * Medium
 * Shuo Feng 
 * 2021.8.2
 */

/*
 *   To get the arrangement of n pair of parenthese ，we need the arrangement of 0 ~(n-1) pair and find a place to insert a pair of parenthese.
 *   
 *   With the arrengement of 'a' pair(s) and 'b' pair(s) of parentheses ( a+b=(n-1) ),  the result should be:
 *                   ♥  ( + 'a' + ) + 'b' 
 *   If 'a' from 0 to (n-1) ,'b' from (n-1) to 0, all cases we can get. ┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓
 *   For example, if n = 3, the result we get: [ ('n = 0')'n = 2' ]     ┃  n = 0: [""]             ┃
 *                                            &[ ('n = 1')'n = 1' ]     ┃  n = 1: ["()"]           ┃
 *                                            &[ ('n = 2')'n = 0' ]     ┃  n = 2: ["()()","(())"]  ┃ (two cases in 'n = 2' should be consider)
 *                                                                      ┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛
 *   So n = 3:["()()()","()(())","(())()","(()())","((()))"]
 */ ☠
 
#include<iostream>
#include<vector>
using namespace std

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> Pairs (n + 1);  // (n + 1): Include 0 pair 
        Pairs[0] = { "" };                    // Case of n = 0
        Pairs[1] = { "()" };                  // Case of n = 1
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                                                // Case number ↓ 
                for     (int place_1 = 0; place_1 < Pairs[j].size();         place_1++) {  
                    for (int place_2 = 0; place_2 < Pairs[i - j - 1].size(); place_2++) {  // i- j- 1 = (i- 1)- j
                        string a = Pairs[j][place_1];          // Case 'place_1' in 'n = j'
                        string b = Pairs[i - j - 1][place_2];  // 
                        string result = "(" + a + ")" + b;
                        Pairs[i].push_back(result);
                    }     
                }
            }
        }
    return Pairs[n];  
    }
    
};
