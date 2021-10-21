/*
 * LeetCode 380 Insert Delete GetRandom O(1)
 * Medium
 * Shuo Feng
 * 2021.10.21
 */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

/*
 * Solution: Hash.
 */

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> map;
  
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if (map.find(val) == map.end()) {
            map[val] = nums.size();
            nums.push_back(val);
            return true;
        }
        else
            return false;
    }

    bool remove(int val) {
        if (map.find(val) != map.end()) {
            int place_val = map[val];
            int place_back = map[nums.back()];

            nums[place_val] = nums[place_back];
            map[nums[place_back]] = place_val;

            map.erase(val);
            nums.pop_back();
            return true;
        }
        else
            return false;
    }

    int getRandom() {
        int idx = rand() % (int)nums.size();
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
