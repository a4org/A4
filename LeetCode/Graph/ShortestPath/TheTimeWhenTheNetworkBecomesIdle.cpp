/* 
 * LeetCode 2039 The Tine When the Network Becomes Idle
 * Medium
 * Jiawei Wang
 * 2021.10.17
 */

// LeetCode Biweekly Contest 63 #3

#include <vector>
#include <iostream>

using namespace::std;


class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        // Every message takes the least amount of time to arrive at the master server.
        // Shortest Path
        // Also the longest path
        // Every data server can be caculated directly after knowing the BFS shortest path
        
        int n = patience.size(); // number of the dataserver
        vector<vector<int>> paths(n);
        
        // Build the paths
        for (vector<int> edge : edges) {
            paths[edge[0]].push_back(edge[1]);
            paths[edge[1]].push_back(edge[0]);
        }
        
        vector<int> Curr, Next;
        vector<int> snodepth(n, -1); // shortest node depth
        int depth = -1;
        Curr.push_back(0);
    
	while (!Curr.empty()) {
	    depth++;
	    for (int i : Curr) {
	    // each child node in this layer
		if (snodepth[i] == -1) {
		   // we never went there before
		   // This is the shortest path
		    snodepth[i] = depth;
		} 
		for (int j : paths[i]) {
		    // Next Level we never met there before
		    if (snodepth[j] == -1) {
			Next.push_back(j);
		    }
		}
	    }
	    Curr.swap(Next);
	    Next.clear();
	}    
	
        int ret = 0;
        // I need to compare all distance with its patience
        for (int i = 1; i < n; i++) {
            int ArriveTime = 2 * snodepth[i] - 1; // the first message back to the data server at "2*snode[i] - 1"
	    int nDataSent = ArriveTime / patience[i]; // number of data we'v sent during this period

	    int lastSent = nDataSent * patience[i]; // the time that the last data be sent
	    int arrived = lastSent + 2 * snodepth[i]; // the Time that data arrived which is what we want
	    ret = max(ret, arrived);
        }
        return ret+1;    
    }
}; 

int main() {
    Solution* Sol = new Solution();
    vector<vector<int>> edges = {{5,7},{15,18},{12,6},{5,1},{11,17},{3,9},{6,11},{14,7},{19,13},{13,3},
	{4,12},{9,15},{2,10},{18,4},{5,14},{17,5},{16,2},{7,1},{0,16},{1,8}, {10,19}};
    vector<int> patience = {0,2,1,1,1,2,2,2,2,1,1,1,2,1,1,1,1,2,1,1};

    cout << Sol->networkBecomesIdle(edges, patience) << endl;
}
