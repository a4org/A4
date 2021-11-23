/* 
 * LeetCode 952 Largest Component Size by Common Factor
 * Hard
 * Jiawei Wang
 * 2021.11.23
 */

#include <vector>
#include <unordered_map>
#include <cmath>

using namespace::std;

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
	vector<int> primes = Eratosthenes(sqrt(L)); // no need to find all primes, just need to find sqrt(L)

	for (int i = 0; i <= L; i++) {
	    Father[i] = i;
	}

	for (int i = 0; i < nums.size(); i++) {
	    int x = nums[i];

	    for (int p : primes) {
		if (x < p) break; // faster

		if (x % p == 0) {
		    // find a group with p as the common factor
		    if (FindFather(nums[i] != FindFather(p))) 
			Union(nums[i], p);
		    while (x % p == 0) x /= p; // if find then x -> 1
		}
	    }
	    if (x > 1) { // x has no prime number that less than sqrt(L)
		if (FindFather(nums[i] != FindFather(x))) {
		    Union(nums[i], x); // group it with itself
		}
	    }
	}

	unordered_map<int, int> count;
	for (int i = 0; i < nums.size(); i++)
	    count[FindFather(nums[i])] += 1;

	int ret = 0;
	for (auto x : count) 
	    ret = max(ret, x.second);
	return ret;
    }

private:
    int L = 100000;
    int Father[100005];
    int m, n;
    int FindFather(int x) {
	// iteration
	if (Father[x] != x) {
	    Father[x] = FindFather(Father[x]);
	}
	return Father[x];
    }

    void Union(int x, int y) {
	// Father[x] = Father[y] = Min(Father[x], Father[y])
	x = Father[x];
	y = Father[y];
	if (x < y) Father[y] = x;
	else Father[x] = y;
    }

    vector<int> Eratosthenes(int n) {
	// Find all primes inside range [0, n]
	// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
	auto q = vector<int> (n+1, 0);
	for (int i = 2; i <= sqrt(n); i++) {
	    if (q[i] == 0) { // a prime
		int j = i*2;
		while (j < n) {
		    q[j] = 1;
		    j += i; // times
		}
	    }
	}
	vector<int> primes;
	for (int i = 2; i <= n; i++) {
	    if (q[i] == 0) 
		primes.push_back(i);
	}
	return primes;
    }
};
