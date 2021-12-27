/*
 * LeetCode 476 Number Complement
 * Easy
 * Jiawei Wang
 * 2021.12.27
 */

#include <iostream>

class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0; // 1111...1

        while (num & mask) mask <<= 1;

        return ~mask & ~num;
    }
};
