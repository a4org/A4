/* 
 * LeetCode 787 Cheapest Flights Within K Stops
 * Medium
 * Jiawei Wang
 * 2022.3.29
 */

#include <vector>
#include <queue>
#include <array>

using namespace::std;
using AI3 = array<int,3>;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
	// DP + Djikstra
	
	// #1 Build the adj
	vector<pair<int, int>> adj[n];

	for (vector<int> flight : flights) {
	    int u = flight[0];
	    int v = flight[1];
	    int price = flight[2];

	    adj[u].push_back(make_pair(v, price));
	    adj[v].push_back(make_pair(u, price));
	}

	// #2 Initialize
	// cheapestpk[i][k] represents the minimumCost to reach destination i with at most k stops
	vector<vector<int>> cheapestpk(n, vector<int>(k, -1)); 

	priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
	pq.push({0, src, k});

	// #3 Djikstra
	while (!pq.empty()) {
	    int price = pq.top()[0];
	    int curr = pq.top()[1];
	    int stops = pq.top()[2];
	    pq.pop();

	    if (cheapestpk[curr][stops] == -1)
		// never visited before
		// must be the shortest
		cheapestpk[curr][stops] = price;
	    else
		price = cheapestpk[curr][stops];

	    if (stops >= 0) {
		for (auto np : adj[curr]) {
		    int n = np.first;
		    int p = np.second;
		    pq.push({p + price, n, stops-1});
		}
	    }
	}

	// #4 get ans
	int ret = INT_MAX;
	for (int p : cheapestpk[dst]) {
	    if (p != -1) {
		ret = min(p, ret);
	    }
	}

	return ret;
    }

    int findCheapestPrice2(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    {
        vector<vector<pair<int,int>>>next(n);        
        for (auto flight: flights)
        {
            int a = flight[0], b = flight[1], w = flight[2];
            next[a].push_back({b, w});
        }            

        vector<vector<int>>cost(n, vector<int>(K+2, INT_MAX/2));
        priority_queue<AI3, vector<AI3>, greater<>>pq;
        pq.push({0, src, 0});        

        while (!pq.empty())
        {
            auto [c, cur, stops] = pq.top();
            pq.pop();
            
            if (cur == dst) return c;
            if (stops == K+1) continue;
            if (cost[cur][stops] < INT_MAX/2) continue;                       
            cost[cur][stops] = c;

            for (auto ticket: next[cur])
            {
                auto [nxt, price] = ticket;
                if (cost[nxt][stops+1] < INT_MAX/2) continue;
                pq.push({c+price, nxt, stops+1});
            }
        }

        return -1;        
    }
};



