/*
 * LeetCode 547 Number of Provinces 
 * Medium
 * Shuo Feng
 * 2021.8.11
 */

/*
 * Thought:
 *   About ' isConnected [i][j] ' : 
 *     ' isConnected[i] ' refers to province ' i '.
 *     and ' isConnected[i][j] ' refers to the relation between province ' i ' and ' j '.
 *
 *   Check each provinces that haven`t visited and sign the provinces which is connected with it.
 *
 *  
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //vector<int> isVisited;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int num = isConnected.size();
        int provinces_num = 0;
        vector<int> isVisited(num, 0);

        for (int i = 0; i < num; ++i) {

            if (isVisited[i] == 0) {
                dfs(isConnected, isVisited, i);
                provinces_num += 1;
            }
        }
        return provinces_num;
    }

    void dfs(vector<vector<int>>& isConnected, vector<int>& isVisited, int i) {
        for (int j = 0; j < isConnected[0].size(); ++j) {
            //isVisited[j] = 1;
            if (isConnected[i][j] == 1 && isVisited[j] != 1) {
                isVisited[j] = 1;
                dfs(isConnected, isVisited, j);
            }
        }
    }

};
