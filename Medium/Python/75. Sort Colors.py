"""
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.


Runtime: 40 ms, faster than 65.10% of Python3 online submissions for Sort Colors.
Memory Usage: 13.1 MB, less than 5.06% of Python3 online submissions for Sort Colors.
"""

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        #Consider doing two pass quicksort style algorithm
        #sort all 0s before all 1s and 2s
        low = 0
        curr =0
        for curr in range(0, len(nums)):
            if nums[curr] == 0:
                nums[low], nums[curr] = nums[curr], nums[low]
                low+=1
        
        #now do again but imagine sorting all 1s before all 2s starting from last 0
        #find last 0
        for low in range(len(nums)-1, 0):
            if nums[low] == 0:
                low+=1
                break
        
        curr = low
        for i in range(low, len(nums)):
            if nums[curr] == 1:
                nums[low], nums[curr] = nums[curr], nums[low]
                low+=1
            curr+=1
        return

