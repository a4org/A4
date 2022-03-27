/* 
 * LeetCode 2093 Minimum Cost to Reach City With Discounts
 * Medium
 * Jiawei Wang
 * 2022.3.26
 */

#include <vector>
#include <queue>
#include <array>

using namespace::std;

using AI3 = array<int, 3>;

class Solution {
public:
    // Djikstra
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
	vector<pair<int, int>> adj[n+1];
	for (auto highway : highways) {
	    int u = highway[0], v = highway[1], len = highway[2];
	    adj[u].push_back({len, v});
	    adj[v].push_back({len, u});
	}

	priority_queue<AI3, vector<AI3>, greater<>> pq;
	pq.push({0, 0, discounts});

	vector<vector<int>> cost(n+1, vector<int>(discounts+1, INT_MAX));

	while (!pq.empty()) {
	    int dist = pq.top()[0];
	    int curr = pq.top()[1];
	    int number = pq.top()[2];

	    pq.pop();

	    if (curr == n-1) return dist;

	    if (dist >= cost[curr][number]) continue;

	    cost[curr][number] = dist;

	    for (auto nxts : adj[curr]) {
		int len = nxts.first;
		int nxt = nxts.second;

		if (cost[nxt][number] != INT_MAX) continue;

		pq.push({dist+len, nxt, number});

		if (number >= 1) {
		    pq.push({dist+len/2, nxt, number-1});
		}

	    }
	}

	return -1;
    }
};
