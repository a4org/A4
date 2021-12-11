#include <vector>
#include <cmath>


using namespace::std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
	int ret = 1;
	int n = bombs.size();
	if (n == 1) return 1;

	vector<int> num(n, 1);

	for (int i = 0; i < n; i++) {
	    vector<int> bomb = bombs[i];
	    int xi = bomb[0];
	    int yi = bomb[1];
	    int ri = bomb[2];
	    for (int j = i+1; j < n; j++) {
		vector<int> bombj = bombs[j];
		int xj = bombj[0];
		int yj = bombj[1];
		int rj = bombj[2];
		if (ri + rj >= getDistance(xi, yi, xj, yj)) {
		    // bomb
		    num[i] = num[j] = num[i] + num[j];
		    ret = max(ret, num[i]);
		}
	    }
	}
	return ret;
    }

private:
    double getDistance(int x1, int y1, int x2, int y2) {
	int x = x2 - x1, y = y2 - y1;
	return sqrt(x*x + y*y);
    }

};
