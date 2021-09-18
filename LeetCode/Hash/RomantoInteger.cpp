/*
 * LeetCode 13 Roman to Integer
 * Easy
 * Shuo Feng
 * 2021.9.18
 */

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
private:
    unordered_map <char, int> table{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
public:
    int romanToInt(string s) {
        int size = s.size();
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            char This = s[i];
            if (i != size - 1 && table.at(s[i]) < table.at(s[i + 1])) {
                sum -= table.at(s[i]);
            }
            else
                sum += table.at(s[i]);
        }
        return sum;
    }
};

