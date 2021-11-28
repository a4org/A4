/*
 * LeetCode 797 All Paths From Source to Target
 * Medium
 * Shuo Feng
 * 2021.11.28
 */

#include<iostream>
#include<vector>
using namespace std;

/*
 * Solution : Dfs with Back Tracking.
 */

class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& path, int place) {
        if (place == graph.size() - 1) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < graph[place].size(); ++i) {
            path.push_back(graph[place][i]);
            dfs(graph, ans, path, graph[place][i]);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;

        path.push_back(0);
        dfs(graph, ans, path, 0);
        return ans;
    }
};
