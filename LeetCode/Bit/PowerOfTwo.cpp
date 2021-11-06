/*
 * LeetCode 231 Power of Two
 * Easy
 * Jiawei Wang
 * 2021.11.6
 */


class Solution {
public:

    bool isPowerOfTwo(int n) {
	// #1 Get Rightmost 1-bit
	// intuition: a power of two in binary representation is one 1-bit, followed by some zeros
	// Because of the two's complement: -x = ~x + 1
	// We using x & (-x) to find the rightmost 1 bit
	if (n == 0) return false; 
	long x = n;
	return (x & (-x)) == x;
    }

    bool isPowerOfTwo2(int n) {
	// #2 Turn off the Rightmost 1-bit
	// x & (x - 1)
	// 100 - 1 = 011
	// 100 & 011 = 000
	if (n == 0) return false;
	long x = n;
	return ((x & (x-1)) == 0);
    }
};
