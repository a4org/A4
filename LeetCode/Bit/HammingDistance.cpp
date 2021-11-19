/*
 * LeetCode 461 Hamming Distance
 * Easy
 * Jiawei Wang
 * 2021.11.19
 */

class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x^y;
        int ret = 0;
        while (diff / 2) {
            ret += diff % 2;
            diff /= 2;
        } 
        ret += diff;
        
        return ret;
    }
};
