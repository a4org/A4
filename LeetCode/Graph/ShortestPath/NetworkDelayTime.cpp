/* 
 * LeetCode 743 Network Delay Time
 * Medium
 * Jiawei Wang
 * 2021.8.10
 */

/**
 * Revision
 * #1 2022.3.19 Jiawei Wang
 */

/*
 * #1 Dijkstra Algorithm
 *
 *
 * #2 DP
 */

#include <vector>
#include <iostream>
#include <queue> // priority queue is the heap in cpp
#include <unordered_map>
#include <unordered_set>

using namespace::std;

typedef pair<int, int> pii;
class Solution {
public:
    // #1 Dijkstra Algorithm
    int networkDelayTime1(vector<vector<int>>& times, int N, int K) {
        vector<vector<pii>>vp(N+1);
        for(const auto& time : times) vp[time[0]].emplace_back(time[1], time[2]);
        vector<bool>visited(N+1, false);
        vector<int>d(N+1, INT_MAX);

        d[0] = 0, d[K] = 0;
        priority_queue<pii,vector<pii>, greater<pii>>pq;  // Min-heap

        pq.emplace(0, K);

        while(!pq.empty()){
            auto [c, u] = pq.top(); // always get the current smallest d (linked)
            pq.pop();
            if (visited[u]) continue;
            for (auto to : vp[u]){
                auto[v, w] = to;
		// try all nodes that near to current node
		// and try to get the minimal distance
                if (c + w < d[v])    {
                    d[v] = c + w;
                    pq.emplace(d[v], v);
                }
            }
            visited[u]=true;
        }
        int res = *max_element(begin(d), end(d));
        return res == INT_MAX ? -1 : res;
    }
    
    // #2 DP
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        constexpr int MAX_TIME = 101 * 100;
        vector<int> dist(N, MAX_TIME);
        dist[K - 1] = 0;
        for (int i = 1; i < N; ++i)
            for (const auto& time : times) {
                int u = time[0] - 1, v = time[1] - 1, w = time[2];
                dist[v] = min(dist[v], dist[u] + w);
            }
        int max_dist = *max_element(dist.begin(), dist.end());
        return max_dist == MAX_TIME ? -1 : max_dist;
    }
};


