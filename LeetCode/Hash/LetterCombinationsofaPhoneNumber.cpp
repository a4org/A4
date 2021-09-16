/*
 * LeetCode 17 Letter Combinations of a Phone Number
 * Medium
 * Shuo Feng
 * 2021.9.16
 */

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

/*
 * Solution: Backtracking
 *
 */


class Solution {
private:
    // Map to show relations between letters and 
    unordered_map<char, string> table{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    // Gathering of combination.
    vector<string> Combinations;

public:
    vector<string> letterCombinations(string digits) {
        // Case of void string.
        if (!digits.size()) return {};

        string combination;  
        Combina(digits, combination, 0);
        return Combinations;
    }
    void Combina(string digits, string combination, int size) {
        if (digits.size() == size) {
            Combinations.push_back(combination);
        }
        else {
            char num = digits[size];
            const string letters = table.at(num);  // Letters related to number " num ".

            for (int i = 0; i < letters.size(); ++i) {
                combination.push_back(letters[i]);
                Combina(digits, combination, combination.size());
                // Tracking back.
                combination.pop_back();
            }
        }
    }
};
