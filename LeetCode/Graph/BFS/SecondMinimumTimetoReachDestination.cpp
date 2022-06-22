/*
 * LeetCode 2045 Second Minimum Time to Reach Destination
 * Hard
 * Jiawei Wang
 * 2022.6.22
 */

#include <vector>
#include <queue>

using namespace::std;
using PII = pair<int, int>;

class Solution {
public:
  // Interesting -> second minimum time
  // in bfs, the second means the second time reach this point (pls think why)
  // which means 2'nd time pop from queue
  int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    vector<int> next[n+1];
    for (auto edge : edges) {
      int a = edge[0], b = edge[1];
      next[a].push_back(b);
      next[b].push_back(a);
    }

    vector<int> visited(n+1, 0);
    vector<int> dist(n+1, -1);

    queue<PII> q;
    q.push({1, 0});
    dist[1] = 0;

    while (!q.empty()) {
      auto current = q.front();
      int curr = current.first;
      int t = current.second;
      q.pop();

      int tt;
      int round = t/change;
      if (round % 2 == 0) {
	// means we are in the green light
	tt = t + time; // go to next point
      } else {
	// wait till green light then go to next point
	tt = (round+1) * change + time;
      }

      // check this point's nexts
      for (int nxt : next[curr]) {
	if (visited[nxt] < 2 && dist[nxt] < tt) {
      // 1. less than 2 means we only need the points that repeated less than 2 times
      // 2. less than tt -> we always wants to find the shorter path if we plan to pass here
	  dist[nxt] = tt;
	  visited[nxt] += 1;
	  q.push({nxt, tt});

	  if (visited[nxt] == 2 && nxt == n)
	    // the 2nd time visited the termination
	    return tt;
	}
      }
    }

    return -1;
  }
};

