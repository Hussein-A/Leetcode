#include<vector>
#include<algorithm>
#include<iostream>

int k = 4;
std::vector<int> k_sum(k, -1);

bool findksum(std::vector<int>& arr, int target, int k) {
	if (k > arr.size() || arr.size() == 0 || k<0) return false;
	--k;
	if (k == 0) {
		bool it = std::binary_search(arr.begin(), arr.end(), target);
		if (it) k_sum.at(k) = *find(arr.begin(), arr.end(), target);
		return it;
	}
	
	for (int i = 0; i < arr.size(); ++i) {
		k_sum.at(k) = arr[i];
		int new_target = target - arr[i];
		if (findksum(arr, new_target, k)) return true;
	}
	return false;
}

int main() {
	std::vector<int> test{ 2,3,4,5,6,7,8,9,10 };
	int target = 16;
	sort(test.begin(), test.end());
	if (findksum(test, target, k)) {
		std::cout << "FOUND\n" << "The " << k << " integers that sum to " << target << " are: \n";
		for (int x : k_sum) { std::cout << x << "\n"; }
	}
	else std::cout << "Not Found!\n";

}