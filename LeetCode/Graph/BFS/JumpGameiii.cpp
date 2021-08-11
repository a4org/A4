/* 
 * LeetCode 1306 Jump Game iii
 * Medium
 * Jiawei Wang
 * 2021.8.11
 */

/*
 * #1 BFS
 *
 *
 * #2 DFS
 *
 */

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace::std;

class Solution {
public:
    // #1 BFS (Correct but TLE)
    int canReach(vector<int>& arr, int start) {
	unordered_map<int, vector<int>> graph;
	unordered_set<int> dest;
	vector<int> Curr, Next;
	int layers = 0;

	if (arr[start] == 0) return true;

	int size = arr.size();
	for (int i = 0; i < size; i++) {
	    if (i + arr[i] < size && arr[i] != 0) graph[i].push_back(i + arr[i]); // right
	    if (i - arr[i] >= 0 && arr[i] != 0) graph[i].push_back(i - arr[i]);   // left
	    if (arr[i] == 0) dest.insert(i); // the destinations
	}
	Curr.push_back(start);

	while(!Curr.empty()) {
	    // This Layer
	    if (layers > size) return false;

	    for (int index : Curr) {
		if (dest.find(index) != dest.end()) return true;
		for (int d : graph[index]) Next.push_back(d);
	    }
	    Curr.swap(Next);
	    Next.clear();
	    layers++;
	}
	return false;
    }

    // #2 BFS faster way
    bool canReach2(vector<int>& arr, int start) {
	const int n = arr.size();
	vector<int> seen(n);
	seen[start] = 1;

	queue<int> q;
	q.push(start);

	while (q.size()) {
	  int cur = q.front();
	  q.pop();
	  if (arr[cur] == 0) return true;
	  for (int i : {-1, 1}) {
	    int t = cur + i * arr[cur];
	    if (t < 0 || t >= n || seen[t]) continue;
	    q.push(t);
	    seen[t] = 1;        
	  }
	}
	return false;
    }


    // #3 DFS
    bool canReach3(vector<int>& arr, int start) {
	const int n = arr.size();
	vector<int> seen(n);
	seen[start] = 1;
	int flag = 0;

	dfs(arr, start, seen, flag);

	if (flag) return true;

	return false;
    }

private:
    void dfs(vector<int>& arr, int curr, vector<int>& seen, int& flag) {
	if (arr[curr] == 0) flag = 1;
	for(int i : {-1, 1}) {
	    int t = curr + i * arr[curr];
	    if (t < 0 || t >= arr.size() || seen[t]) continue;
	    seen[t] = 1;
	    dfs(arr, t, seen, flag);
	}
    }
};



