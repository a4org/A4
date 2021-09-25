/*
 * LeetCode 17 Letter Combinations of a Phone Number
 * Medium
 * Shuo Feng
 * 2021.9.16
 * Last edited at 2021.9.26
 */

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

/*
 * Solution: Backtracking
 *   See each combination as a tree.
 *   For example, if digits = "23": 
 *                                                   null 
 *                                    /               |               \
 * Combination we already have:     a                 b                 c     | If we already have "a", when we select (1)'d' as the next letter, the combination is complete,
 *                                / | \             / | \             / | \   | after that what we should consider is other combination, in this phase, we need only back to "a",
 * Next letter we can select:    d  e  f           d  e  f           d  e  f  | and select other letter (2)'e', a new combination is formed.
 * Selected place:              (1)(2)(3)                                     |
 * Combination we get            ad ae af          bd be bf          cd ce cf |
 *                                                                            |
 *  result: ["ad","ae","af","bd","be","bf","cd","ce","cf"].
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
    
    //explanation:( digit         , combination we already have , size of this ←─ combination).     
    void  Combina ( string digits , string combination          , int size                   ) {
        
        // Collect combination when it`s length meets requirements(meet digits size).
        if (digits.size() == size) {
            Combinations.push_back(combination);
        }
        
        else {
            char num = digits[size];               // Start with place 'size + 1' in digits, because a 'size'_length combination is already formed. 
            const string letters = table.at(num);  // Letters related to number " num ".

            for (int i = 0; i < letters.size(); ++i) {
                combination.push_back(letters[i]); // Add next letter.
                Combina(digits, combination, combination.size());
                // Tracking back, back to previous combination.
                combination.pop_back();
            }
        }
    }
};
