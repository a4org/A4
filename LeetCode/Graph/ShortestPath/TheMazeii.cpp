/* 
 * LeetCode 505 The Maze ii
 * Medium
 * Jiawei Wang
 * 2022.3.19
 */

/**
 * Dijkstra's Algorithm
 * BFS + PQ
 * Weight shortestDistance
 * greedy
 */

#include <queue>
#include <vector>

using namespace::std;

typedef vector<int> VI;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
	int m = maze.size();
	int n = maze[0].size();

	// a classic trick
	auto dir = vector<pair<int, int>>({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});

	priority_queue<VI, vector<VI>, greater<>> pq;

	pq.push({0, start[0], start[1]});

	auto resolved = vector<VI>(m, vector<int>(n, 0));

	// BFS
	while (!pq.empty()) {
	    int d = pq.top()[0];
	    int x = pq.top()[1];
	    int y = pq.top()[2];
	    pq.pop();

	    // current shortest distance
	    if (x == destination[0] && y == destination[1]) {
		return d;
	    }

	    if (resolved[x][y] == 1) 
		continue;

	    resolved[x][y] = 1;

	    // four directions
	    for (int k = 0; k < 4; k++) {
		int i = x, j = y, dist = 0;
		while (i + dir[k].first >= 0 && i + dir[k].first < m && j + dir[k].second >= 0 &&
			j + dir[k].second < n && maze[i+dir[k].first][j+dir[k].second] != 1) {
		    dist++;
		    i += dir[k].first;
		    j += dir[k].second;
		}

		if (resolved[i][j] == 1) 
		    continue;
		pq.push({d+dist, i, j});
	    }
	}
	return -1;
    }
};

