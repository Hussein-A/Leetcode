/*
Count the number of prime numbers less than a non-negative number, n.

Runtime: 92 ms, faster than 38.50% of C++ online submissions for Count Primes.
Memory Usage: 8.5 MB, less than 80.13% of C++ online submissions for Count Primes.
*/

class Solution {
public:
	int countPrimes(int n) {
		if (n == 0 || n == 1) return 0;
		//sieve of erostathene
		int size = n + 1;
		vector<bool> nums(size, true);

		//0 and 1 are not primes
		nums[0] = nums[1] = false;
		nums[size - 1] = false;

		//remove all products of primes
		int curr_prime = 2;
		while (curr_prime <= n / 2) {
			//cout << "current prime is: " << curr_prime << "\n";
			for (int multiple = 2; multiple <= n / curr_prime; ++multiple) { nums[multiple * curr_prime] = false; }
			// cout << "vector after removing products is: "; for (int i = 0; i < nums.size(); ++i) { if (nums[i]) { cout << "1 "; } else cout << "0 "; }
			 //cout << "\n";
			 //find next prime
			bool found_next = false;
			int i = curr_prime + 1;
			while (!found_next) { if (nums[i]) { curr_prime = i; found_next = true; } ++i; }
		}

		return count(nums.begin(), nums.end(), true);
	}
};