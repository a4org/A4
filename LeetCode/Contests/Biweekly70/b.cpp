#include <vector>

using namespace::std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long low = INT_MAX;
        long big = INT_MIN;
        long bias = 0;
        long minstart = 0, maxstart = 0;
        
        for (int i = 0; i < differences.size(); i++) {
            bias += differences[i];
            if (bias < low) low = bias;
            if (bias > big) big = bias;
        }
        if (low >= 0) minstart = lower;
        else minstart = lower - low;
        
        if (big <= 0) maxstart = upper;
        else maxstart = upper - big;
        
        if (minstart > maxstart) return 0;
        
        return maxstart - minstart + 1;
    }
};
