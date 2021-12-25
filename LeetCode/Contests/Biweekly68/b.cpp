#include <cstddef>
#include <string>
#include <unordered_set>
#include <vector>

using namespace::std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
	vector<string> ret = {};
	unordered_set<string> sset(supplies.begin(), supplies.end()); // static hashing

	int size = -1;
	while (ret.size() != size) {
	    size = ret.size();
	    for (vector<string> &re : ingredients) {
		vector<string> tre;
		for (int i = 0; i < re.size(); i++) {
		    if (sset.find(re[i]) == sset.end()) {
			tre.push_back(re[i]);
		    }
		}
		re = tre;
	    }

	    for (int i = 0; i < ingredients.size(); i++) {
		if (!ingredients[i].size() && sset.find(recipes[i]) == sset.end()) {
		    // can produce
		    sset.insert(recipes[i]);
		    ret.push_back(recipes[i]);
		}
	    }
	}
	return ret;
    }
};
