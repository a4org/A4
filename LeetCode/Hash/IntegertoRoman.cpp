/*
 * LeetCode 12 Integer to Roman
 * Medium
 * Shuo Feng
 * 2021.9.18
 */
 
 #include<iostream>
#include<vector>
#include<string>
#include<utility>
using namespace std;

class Solution {
private:
    // All possible cases.
    vector<pair<int, string>> table{
        {1000, "M" },
        {900,  "CM"},
        {500,  "D" },
        {400,  "CD"},
        {100,  "C" },
        {90,   "XC"},
        {50,   "L" },
        {40,   "XL"},
        {10,   "X" },
        {9,    "IX"},
        {5,    "V" },
        {4,    "IV"},
        {1,    "I" }
    };
public:
    string intToRoman(int num) {
        string sum;
        // Search the table from head to tail, ensure that reach the maximum value which is possible at first
        for (int i = 0; i < 13; ++i) {
            while (num >= table[i].first) {
                sum += table[i].second;
                num -= table[i].first;
            }
            if (num == 0) break;
        }
        return sum;
    }
};
