"""
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.

Runtime: 36 ms, faster than 79.36% of Python3 online submissions for Length of Last Word.
Memory Usage: 13.3 MB, less than 6.04% of Python3 online submissions for Length of Last Word.
"""

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        words = s.split()
        if len(words) == 0: return 0
        else: return len(words[-1])
