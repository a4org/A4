/*
 * LeetCode 380  Insert Delete GetRandom O(1)
 * Medium
 * Jiawei Wang
 * 2021 10.21
 */

#include <unordered_map>
#include <unordered_set>
#include <vector>


using namespace::std;

// You must implement the functions of the class such that each function works in average O(1) time complexity.

class RandomizedCollection {
public:
    RandomizedCollection() {
    }
    
    bool insert(int val) {
	int flag = val2pos.find(val) == val2pos.end();
	nums.push_back(val);
	val2pos[val].insert(nums.size() - 1);
	return flag;
    }
    
    bool remove(int val) {
	int flag = val2pos.find(val) != val2pos.end();
	if (flag == false) return false;

	int val2 = nums.back();

	if (val2 == val) {
	    // just delete the back element
	    val2pos[val].erase(nums.size() - 1);
	    nums.pop_back();
	    
	    if (val2pos[val].size() == 0) val2pos.erase(val);
	} else {
	    int pos2 = nums.size() - 1;  // element to be swapped
	    int pos = *(val2pos[val].begin()); // the element to be deleted

	    val2pos[val2].erase(pos2);
	    val2pos[val2].insert(pos);

	    nums[pos] = val2;
	    val2pos[val].erase(pos);
	    nums.pop_back();

	    if (val2pos[val].size() == 0) val2pos.erase(val);
	}
	return flag;
    }
    
    int getRandom() {
	int idx = rand() % nums.size();
	return nums[idx];
    }
private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> val2pos;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
