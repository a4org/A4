/* 
 * LeetCode 882. Reachable Nodes in Subdivided Graph
 * Hard
 * Jiawei Wang
 * 2022.3.22
 */

#include <vector>
#include <queue>

using namespace::std;

using LL = long long;
using PLI = pair<LL, int>; 

class Solution {
public:
    LL mindist[3001]; // minimum dist from 0 to i
    vector<PLI> adj[3001];
    int visited[3001]; // whether we visited before
    // Dijkstra
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
	int ret = 1;
	// 0. Init
	for (auto edge : edges) {
	    int u = edge[0];
	    int v = edge[1];
	    int len = edge[2] + 1;
	    adj[u].push_back({len, v});
	    adj[v].push_back({len, u});
	}

	for (int i = 0; i <= n; i++) {
	    mindist[i] = -1;
	}

	// 1. dijkstra
	priority_queue<PLI, vector<PLI>, greater<>> pq; // {mindist, edge}

	pq.push({0, 0});

	while (!pq.empty()) {
	    LL mdist = pq.top().first;
	    int node = pq.top().second;

	    pq.pop();

	    if (mindist[node] != -1) continue;

	    mindist[node] = mdist; // assign

	    for (PLI nxt : adj[node]) {
		// append next into pq
		LL len = nxt.first;
		int nt = nxt.second;
		if (mindist[nt] != -1) continue;
		pq.push({len + mdist, nt});
	    }
	}

	for (int i = 0; i < n; i++) {
	    visited[i] = -1;
	}

	// 2. Go through each edge
	for (auto edge : edges) {
	    int u = edge[0];
	    int v = edge[1];
	    int np = edge[2]; // number of points

	    int su = 0;  // start from u
	    int sv = 0;  // start from v
	    
	    helper(su, np, u, maxMoves, ret);
	    helper(sv, np, v, maxMoves, ret);

	    if (su + sv <= np) ret += su + sv;
	    else ret += np;
	}

	return ret;
    }

private:
    void helper(int& s, int np, int p, int maxMoves, int& ret) {
	if (mindist[p] == -1) return;
	if (mindist[p] <= maxMoves) {
	    if (visited[p] == -1 && p != 0) {
		ret += 1;
		visited[p] = 1;
	    }
	    int tmp = maxMoves - mindist[p];
	    if (tmp >= np) s = np;
	    else s = tmp;
	}
    }
};
