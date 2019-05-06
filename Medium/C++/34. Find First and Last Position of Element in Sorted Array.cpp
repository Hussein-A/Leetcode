/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].

Runtime: 8 ms, faster than 99.59% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
Memory Usage: 10.7 MB, less than 96.77% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //check if exists at all
        if (!binary_search(nums.begin(), nums.end(), target)) return {-1, -1};
        int vec_size = nums.size();
        
        vector<int> index(2);
        index[0] = binary_helper2(nums, 0, vec_size-1, target);
        index[1] = binary_helper1(nums, 0, vec_size-1, target);
        
        if (nums[index[0]] != target && vec_size!= 1) ++index[0];
        if (nums[index[1]] != target && vec_size!= 1) --index[1];
        return index;
    }
private: 
    int binary_helper1(vector<int>& nums, int low, int high, int target){
        //do modified binary search
        //find right end
        
        if (low >= high) return low;
        int middle = low + (high-low)/2;
        
        if (nums[middle] > target)
            return binary_helper1(nums, low, middle-1, target);
        else
            return binary_helper1(nums, middle+1, high, target);
    }
    int binary_helper2(vector<int>& nums, int low, int high, int target){
        //find left end
        if (low >= high) return low;
        int middle = low + (high-low)/2;
        
        if (nums[middle] >= target)
            return binary_helper2(nums, low, middle-1, target);
        else
            return binary_helper2(nums, middle+1, high, target);
    }
};
