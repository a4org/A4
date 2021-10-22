/*
 * LeetCode 451 Sort Characters By Frequency
 * Medium
 * Shuo Feng
 * 2021.10.23
 */

#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

/*
 * Solution: Hash Table
 */

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        int size = s.size();
        for (char i : s) {
            map[i] += 1;
        }

        string res;
        vector<pair<char, int>> freq(map.begin(), map.end());
        sort(freq.begin(), freq.end(),
            [](const pair<char, int>& a1, const pair<char, int>& a2) {
                return a1.second > a2.second;
            }
        );

        for (auto pairs : freq) {
            for (int i = 0; i < pairs.second; ++i) {
                res.push_back(pairs.first);
            }
        }
        return res;
    }

    //struct Compare {
    //    bool Compare_freq()(const pair<char, int>& a1, const pair<char, int>& a2){
    //        return a1.second > a2.second;
    //    }

};
