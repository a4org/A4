#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        int num1 = num % 10;
        num /= 10;
        int num2 = num % 10;
        num /= 10;
        int num3 = num % 10;
        num /= 10;
        int num4 = num % 10;
        num /= 10;

        vector<int> nums = { num1, num2, num3, num4 };
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[2] * 10 + nums[0] + nums[3] * 10 + nums[1];
    }
};
