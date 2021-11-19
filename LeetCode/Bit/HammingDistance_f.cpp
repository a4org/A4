/*
 * LeetCode 461 Hamming Distance
 * Easy
 * Shuo Feng
 * 2021.11.19
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution: Bit
 */

class Solution {
public:
    int hammingDistance(int x, int y) {
        // Find all different bits.
        int z = x ^ y;

        // Turn decimal to binary.
        string binary;
        while (z != 0) {
            binary += '0' + z % 2;
            z /= 2;
        }
        //reverse(binary.begin(), binary.end());

        int res = 0;
        for (char c : binary)
            if (c == '1') res += 1;
        return res;
    }
};
