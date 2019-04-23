#Write a function that reverses a string. The input string is given as an array of characters char[].
#Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
#You may assume all the characters consist of printable ascii characters.

#Runtime: beats 93.21 % of python submissions.
#MEM: memory usage beats 14.92 % of python submissions.

class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        half = (int)(len(s)-1)/2
        last = (len(s)-1)
        print(len(s))
        print(half)
        for i in range(0, half+1):
            s[i], s[last-i] = s[last-i],s[i]
