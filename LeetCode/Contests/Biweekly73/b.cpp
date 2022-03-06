#include <vector>
#include <unordered_map>
#include <string>

using namespace::std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, vector<int>> mnum = {};
        vector<int> mapped = {};
        for (int num : nums) {
            int transfer = this->helper(mapping, num);
            mnum[transfer].push_back(num);
            if (mnum[transfer].size() == 1)
                mapped.push_back(transfer);
        }
        
        sort(mapped.begin(), mapped.end());
        vector<int> ret = {};
        
        for (int i : mapped) {
            for (int j : mnum[i]) {
                ret.push_back(j);
            }
        }
        return ret;
    }
private:
    int helper(vector<int> mapping, int num) {
        // Transfer num into its mapped value
        string tmp = to_string(num);
        string transfer = "";
        for (char c : tmp) {
            transfer += to_string(mapping[(c-48)]);
        }
        
        if (transfer[0] == '0') {
            for (int i = 0; i < transfer.size(); i++) {
               if (transfer[i] != '0') {
                    transfer = transfer.substr(i);
                    break;
                } 
            }     
        }    
        return stoi(transfer);
    }
}; 
