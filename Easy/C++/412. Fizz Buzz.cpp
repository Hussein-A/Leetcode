//Write a program that outputs the string representation of numbers from 1 to n.
//But for multiples of three it should output “Fizz” instead of the number and for the multiples of 
//five output “Buzz”.For numbers which are multiples of both three and five output “FizzBuzz”.
//Speed: (8ms) Faster than 100% of C++ submissions; Mem: (9.7mb) less than 99.34% of C++ submissions

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> fizz(n);
		for (int i = 1; i <= n; ++i) {
			if (i % 15 == 0) { fizz[i - 1] += "FizzBuzz"; }
			else if (i % 3 == 0) { fizz[i - 1] += "Fizz"; }
			else if (i % 5 == 0) { fizz[i - 1] += "Buzz"; }
			else { fizz[i - 1] = to_string(i); }
		}
		return fizz;
	}
};