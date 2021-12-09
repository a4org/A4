/*
 * LeetCode 1306 Jump Game iii
 * Medium
 * Shuo Feng
 * 2021.12.9
 */

#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

/*
 * Solution 1: Dfs & Hash Table
 */

class Solution {
private:
    // Storage all passed point.
    // When meet passed point -> wrong way.
    unordered_set<int> passed;
    bool helper(vector<int>& arr, int start, int size) {

        if (start >= size || start < 0) {
            return false;
        }

        int startIndex = arr[start]; // Value of start point
        if (startIndex == 0)
            return true;

        if (passed.find(start) != passed.end())
            return false;

        passed.emplace(start);
        return (helper(arr, start + startIndex, size) || helper(arr, start - startIndex, size));
    }

public:
    bool canReach(vector<int>& arr, int start) {
        int size = arr.size();
        return helper(arr, start, size);
    }
};


/*
 * Better Solution: Bfs
 */

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int size = arr.size();
        vector<int> passed(size);
        passed[start] = 1;

        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (arr[cur] == 0)
                return true;

            // Two directions.
            for (int i : {1, -1}) {
                int index = cur + i * arr[cur];
                if (index >= size || index < 0 || passed[index] == 1)
                    continue;
                passed[index] = 1;
                q.push(index);
            }
        }
        return false;
    }
};
