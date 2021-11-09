/*
 * LeetCode 1178 Number of Valid Words for Each Puzzle
 * Hard
 * Shuo Feng
 * 2021.11.9
 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
 * Solution: HashTable.
 *   By turn word into binary, we can find whether a letter has appeared easily.
 *   For ex:  "acd" ->   0 ... 0 0 1 1 0 1
 *                      [z ... f e d c b a].
 *
 *
 */

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> freq;

        
        for (string word : words) {
            // mask : outcome of turn word into binary.
            int mask = 0;
            for (char ch : word) {
                //                ch - 'a'  : count the letter`s place in letters table.
                //          1 << (ch - 'a') : set correspond place as 1.
                // mask |= (1 << (ch - 'a')): storage in mask.
                mask |= (1 << (ch - 'a'));
            }
            freq[mask] += 1;
        }

        vector<int> res;
        for (string puzzle : puzzles) {
            int total = 0;  // How many words match.
            int mask = 0;   // Puzzle mask.
          
            // Same as line 31.
            // Begin with puzzle[1].
            //   explain: the word should contain the first letter of puzzle, each time add puzzle[0] in fornt of subset.(line 55)
            for (int i = 1; i < 7; ++i) {
                mask |= (1 << (puzzle[i] - 'a'));
            }

          
            // Enumerate subsets of puzzle, find corresponding words.
            int sub = mask;
            do {
                // Add the front letter.
                int s = sub | (1 << (puzzle[0] - 'a'));
                
                // Check in table.
                if (freq.count(s)) {
                    total += freq[s];
                }
              
                sub = (sub - 1) & mask;                               
            } while (sub != mask); // ▼ When sub = 0, (0 - 1) & mask = mask -> end cycle.

            res.push_back(total);
        }
        return res;
    }
};
