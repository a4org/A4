/* 
 * LeetCode 1976 Number of Ways to Arrive at Destination
 * Medium
 * Jiawei Wang
 * 2022.3.20
 */


// Dijkstra: 
// single source, non-negative weight


#include <vector>
#include <queue>

using namespace::std;
using LL = long long;
using PII = pair<LL, LL>;

class Solution {
    LL dist[201];  // dist[i]: the shortest dist from 0 to i
    vector<PII> adj[201];
    LL count[201]; //
    LL M = 1e9+7;

public:
    int countPaths(int n, vector<vector<int>>& roads) {
	// #1 using dijkstra algorithm find the minimum distance
	// bfs + priority_queue
	for (auto road : roads) {
	    int u = road[0], v = road[1], len = road[2];
	    adj[u].push_back({v, len});
	    adj[v].push_back({u, len});
	}

	for (int i = 0; i < n; i++) {
	    dist[i] = -1;
	}

	priority_queue<PII, vector<PII>, greater<>> pq; // {dist, city}
	pq.push({0, 0});

	while (!pq.empty()) {
	    LL d = pq.top().first;  // dist
	    LL c = pq.top().second; // city
	    pq.pop();
	    if (dist[c] != -1) {
		continue;
	    }
	    // never visited before, current optimized solution
	    else {
		dist[c] = d;
	    }

	    for (auto x : adj[c]) {
		LL nxt = x.first;
		LL len = x.second;
		if (dist[nxt] != -1) continue;
		pq.push({d+len, nxt});
	    }
	}

	// Now dist[i-1] is the min distance
	
	for (int i = 0; i < n; i++) {
	    count[i] = -1;
	}
	
	// 2. using dfs to find the number of min distance
	return dfs(n-1, dist[n-1]);
    }

private:
    LL dfs(int curr, LL d) {
	// return the number of min distance (d) that pass curr
	if (dist[curr] != d) {
	    return 0; // not count
	}

	if (curr == 0) return 1;

	if (count[curr] != -1) {
	    return count[curr];
	}

	LL total = 0;

	for (auto x : adj[curr]) {
	    LL nxt = x.first;
	    LL len = x.second;
	    total += dfs(nxt, d - len);
	    total %= M;
	}

	count[curr] = total;
	return total;
    }
};
