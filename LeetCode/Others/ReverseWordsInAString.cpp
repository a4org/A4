/*
 * LeetCode 151 Reverse Words In A String
 * Medium
 * Shuo Feng
 * 2021.10.20
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution:
 *   To reverse words, we can reverse all string first, after this procedure each words are placed at position correspond with result.
 *   A major problem that should be considered is how to avoid extra space, to solve this problem, use 'idx' to represent the place 
 *  after a word, so the place after idx is where next word start with, when reverse next word, move it to place after idx, 
 *  by this way we can ensure that only one space between each words.
 *
 *   For ex:   
 *                                         ↓ a space
 *      ├────┤ hello ├────┤ ├────┤ world ├────┤
 * after reverse string:
 *      ├────┤ dlrow ├────┤ ├────┤ olleh ├────┤
 *        ↑ idx = 0: move "dlrow" to head place.
 *      dlrow   w    ├────┤ olleh ├────┤
 * reverse first word:
 *      world   w    ├────┤ olleh ├────┤
 *              ↑ now idx is here, set idx as ' '.
 *      world ├────┤ ├────┤ olleh ├────┤
 *                     ↑ move idx to this place, as the start point of next word.
 *      world ├────┤  olleh   h   ├────┤
 * reverse word2:             ↑ idx  
 *      world ├────┤  hello   h   ├────┤
 * resize:
 *      world ├────┤  hello
 */


class Solution {
public:
    string reverseWords(string s) {
        // Reverse string.
        reverse(s.begin(), s.end());

        int size = s.size();
        int idx = 0;
        for (int start = 0; start < size; ++start) {
            if (s[start] != ' ') {
              
                // Set idx as ' ', and move to next place, when idx not at first place.
                if (idx != 0)
                    s[idx++] = ' ';

                int end = start;
                // Move word.
                while (end < size && s[end] != ' ')
                    s[idx++] = s[end++];

                // Reverse a word.
                // begin + idx : space after word,  end - start: word length.
                reverse(s.begin() + idx - (end - start), s.begin() + idx);
                start = end;
            }
        }
        s.resize(idx);
        return s;
    }
};
