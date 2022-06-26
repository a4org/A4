#include <vector>

using namespace::std;

class Solution {
public:
  int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int sum1 = 0;
    int sum2 = 0;
    int ret = 0;

    for (int i = 0; i < n; i++) {
      int n1 = nums1[i];
      int n2 = nums2[i];
      sum1 += n1;
      sum2 += n2;
    }

    ret = max(sum1, sum2);

    // nums1
    for (int i = 0; i < n; i++) {
      int n1 = nums1[i];
      int n2 = nums2[i];
    }



  }
};
