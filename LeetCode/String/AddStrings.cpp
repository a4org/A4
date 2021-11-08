/*
 * LeetCode 415 Add Strings
 * Easy
 * Shuo Feng
 * 2021.11.8
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution:
 *   Think as human being.
 *   From tail to head, add the two number on corresponding place(denoted as x), if x bigger than 10, update add.
 */

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";

        int p1 = num1.size() - 1;
        int p2 = num2.size() - 1;
        int add = 0;  // Carry.

        while (p1 >= 0 || p2 >= 0 || add != 0) {
            // char -> int.
            int n1 = p1 >= 0 ? num1[p1] - '0' : 0;
            int n2 = p2 >= 0 ? num2[p2] - '0' : 0;

            int x = n1 + n2 + add;
            // int -> char.
            // Take the remainder.
            res.push_back('0' + x % 10);
            add = x / 10;

            p1 -= 1;
            p2 -= 1;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
