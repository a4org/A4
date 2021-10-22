/*
 * LeetCode 451 Sort Characters By Frequency
 * medium
 * Jiawei Wang
 * 2021 10.22
 */

#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>

using namespace::std;


class Solution {
public:
    // #1 Using map and vector sort by value
    string frequencySort(string s) {
        // Map
        unordered_map<char, int> c2freq;
        
        for (auto c : s) {
            c2freq[c]++;
        }

        string ret;
	vector<PAIR> c2freqv(c2freq.begin(), c2freq.end());
	sort(c2freqv.begin(), c2freqv.end(), CmpByValue());
	for (auto pairs : c2freqv) {
	    int nums = pairs.second;
	    char c = pairs.first;
	    for (int i = 0; i < nums; i++) {
		ret += c;
	    }
	}
	return ret;

    }

// define the compare function
typedef pair<char, int> PAIR;

struct CmpByValue {
    bool operator()(const PAIR& lhs, const PAIR& rhs) {
	// override operator()
	// example
	// struct Accumulator {
	//     int counter = 0;
	//     int operator() (int i) { return counter += 1; }
	// }
	//
	//
	// Accumulator acc;
	// cout << acc(10) << endl; // 10
	// cout << acc(20) << endl; // 30
	return lhs.second > rhs.second;
  }
};

};


