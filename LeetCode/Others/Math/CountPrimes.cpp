/*
 * LeetCode 204 Count Primes
 * Easy
 * Jiawei Wang
 * 2021 9.1
 */

#include <vector>
#include <cmath>
#include <numeric>

using namespace::std;

// sieve of Eratosthenes:
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

class Solution {
private:
    bool isPrime(int n) {
	if (n <= 2) return false;
	for (int x = 2; x <= n-1; x++) {
	    if (n % x == 0) return false;
	}
	return true;
    }
public:
    // #1 Brute Force
    // Time Complexity: O(n^2)
    int countPrimes1(int n) {
	int ans = 0;
	if (n < 3) return 0;
	for (int i = 3; i <= n; i++) {
	    if (isPrime(i)) ans++;
	}
	return ans;
    }

    // #2 sieve of Eratosthenes
    // Time Complexity: O(nloglogn)
    int countPrimes2(int n) {
	if (n < 3) return 0;
	vector<unsigned char> f(n, 1);  // f[i] == 1 represents that number i-1 is a prime number
	f[0] = f[1] = 0; 
	for (long l = 2; l <= sqrt(n); ++l) {
	    if (!f[l]) continue; // if it is already not a prime number, skip
	    for (long j = l*l; j < n; j+=l) {
		// multiple times (2, 4, 6, 8...)
		f[j] = 0;
	    }
	}

	// Computes the sum of the given value init and the elements in the range [first, last)
	int ans = accumulate(f.begin(), f.end(), 0);
	return ans;
    }
};
