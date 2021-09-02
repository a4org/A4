/* 
 * LeetCode 310 Minimum Height Trees
 * Medium
 * Jiawei Wang
 * 2021.9.2
 */

/*
 * BFS From leaves
 *
 * 3  2  1
 * \  |  /
 *    4    <-- answer
 *    | 
 *    0
 *
 * Key idea, the MHT root must in the "mid" of a graph
 * Keep search all leaf nodes each layer
 */

#include <vector>
#include <unordered_set>
#include <queue>

using namespace::std;

class Solution {
public:
    // #1 BFS From root (Possible but TLE)


    // #2 BFS From leaves
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<int> res; // result
        vector<unordered_set<int>> nodes(n);
        queue<int> q; // q stores all current leaf nodes
        for (auto edge : edges) {
            nodes[edge[0]].insert(edge[1]);
            nodes[edge[1]].insert(edge[0]);
        }

        for (int i = 0; i < n; ++i) {
	    // initial all leave nodes
            if (nodes[i].size() == 1) q.push(i);
        }
        while (n > 2) { // understand this
	    // In ay cases: there are only maximum two possible roots (1 or 2)
	    // since 3 nodes will produce 2 leaf nodes
	    // (1) there are no cycle in the graph 
	    // (2) when n > 2, they are not leaf nodes
            int size = q.size();
            n -= size;
            for (int i = 0; i < size; ++i) {
                int t = q.front(); q.pop();
                for (auto a : nodes[t]) {
		    //the only node connected with this leaf node will erase a connected node
                    nodes[a].erase(t); 
		    // key: if it becomes a leaf graph, push it to q
                    if (nodes[a].size() == 1) q.push(a);
                }
            }
        }
        while (!q.empty()) {
            res.push_back(q.front()); q.pop();
        }
        return res;
    }
};

