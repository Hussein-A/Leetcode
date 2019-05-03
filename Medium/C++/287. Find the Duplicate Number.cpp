/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Proof (sketch): Using pigeon hole principle.

Runtime beats 99.02 % of cpp submissions
Memory usage beats 10.38 % of cpp submissions.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];
        
        while (true){
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
            if (tortoise == hare) break;
        }
        
        int first = nums[0];
        int second = tortoise;
        
        while (first != second){
            first = nums[first];
            second = nums[second];
        }
        
        return first;
    }
};
