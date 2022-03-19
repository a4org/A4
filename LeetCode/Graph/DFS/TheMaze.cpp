/* 
 * LeetCode 490 The Maze
 * Medium
 * Jiawei Wang
 * 2022.3.19
 */


#include <vector>
#include <set>
#include <queue>

using namespace::std;

typedef vector<int> VI;

class Solution {
public:
    // 1. DFS
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        set<vector<int>> visited;
        return helper(maze, start, destination, visited);
    }

    // 2. BFS
    bool hasPathii(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
	int m = maze.size();
	int n = maze[0].size();

	// a classic trick
	auto dir = vector<pair<int, int>>({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});

	queue<VI> qe;

	qe.push({start[0], start[1]});

	auto resolved = vector<VI>(m, vector<int>(n, 0));

	while (!qe.empty()) {
	    int x = qe.front()[0];
	    int y = qe.front()[1];
	    qe.pop();

	    // find destination
	    if (x == destination[0] && y == destination[1]) {
		return true;
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
		qe.push({i, j});
	    }
	}
	return false;
    }

private:
    bool helper(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination, set<vector<int>>& visited) {
        if(start == destination) return true;
        if(visited.find(start) != visited.end()) return false;
        visited.insert(start);
	vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	for(int i = 0; i < 4; i++) {
	    // four directions
            vector<int> res = go2End(maze, start, dirs[i]);
            if(res == destination || helper(maze, res, destination, visited)) return true;
        }
        return false;
    }
    vector<int> go2End(vector<vector<int>>& maze, vector<int>& start, vector<int>& dir) {
	// Go one step further, won't change direction
        int i = start[0] + dir[0];
        int j = start[1] + dir[1];
        int m = maze.size();
        int n = maze[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || maze[i][j] == 1) {
	    // Termination Condition
            return start;
        }
        vector<int> newStart = {i, j};
        return go2End(maze, newStart, dir);
    }
};

