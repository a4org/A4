/*
 * LeetCode 380  Insert Delete GetRandom O(1)
 * Medium
 * Jiawei Wang
 * 2021 10.21
 */

#include <unordered_map>
#include <vector>


using namespace::std;

// You must implement the functions of the class such that each function works in average O(1) time complexity.

class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
	// vector push_back O(1) time
	if (Map.find(val) != Map.end()) {
	    // Map find element take avg constant time
		return false;
	} else {
	    Map[val] = q.size(); // push back
	    q.push_back(val);
	    return true;
	}
    }
    
    bool remove(int val) {
	// vector pop_back O(1) time
	if (Map.find(val) == Map.end()) {
	    return false;
	} else {
	    q[Map[val]] = q.back(); // swap
	    Map[q.back()] = Map[val];
	    q.pop_back();
	    Map.erase(val);
	    return true;
	}
    }
    
    int getRandom() {
	int pos = rand() % q.size();
	return q[pos];
    }

private:
    unordered_map<int, int> Map; // map the position in q and the value of q
    vector<int> q; // q[Map[val]] -> Val
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

