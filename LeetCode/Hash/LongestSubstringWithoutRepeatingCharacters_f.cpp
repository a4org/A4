/*
 * LeetCode 3 Longest Substring Without Repeating Characters
 * Medium
 * Shuo Feng
 * 2021.9.15
 */

/*
 * Solution 1: 
 *   Begin with a starting point and check characters after, update a set and record the maximum size.
 *   When meet a repeating character, remove the previous point in set till there have not repeat, change starting point in " s ".
 *
 *   a     b     c     a     b     c     b     b     Longest Substring:
 *   Begin             ↑(Find repeat)                (abc)
 *   a     b     c     a     b     c     b     b     
 *         Begin             ↑                       (bca)
 *   a     b     c     a     b     c     b     b     
 *               Begin             ↑                 (cab)
 *   a     b     c     a     b     c     b     b     
 *                     Begin             ↑           (abc) 
 *   a     b     c     a     b     c     b     b     
 *                           Begin       ↑           (bc)
 *   a     b     c     a     b     c     b     b     
 *                                 Begin       ↑     (cb)
 *   a     b     c     a     b     c     b     b     
 *                                       Begin ↑     (b)
 *   a     b     c     a     b     c     b     b     
 *                                             Begin (b) 
 */

#include<iostream>
#include<string>
#include<utility>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if (size < 2) return size;

        int max_size = 0;
        int Begin = 0; // Begining place.

        unordered_set <char> search;
        for (int i = 0; i < size; ++i) {

            // Search in set.
            // Repetitive.
            while (search.find(s[i]) != search.end()) {
                search.erase(s[Begin]);
                Begin += 1; // Begin with next point.
            }

            // non_Repetitive.
            search.insert(s[i]);
            max_size = max(max_size, i - Begin + 1);

        }
        return max_size;
    }
};
