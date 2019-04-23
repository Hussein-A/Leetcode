#Given an integer, write a function to determine if it is a power of two.

#Runtime: 52 ms, faster than 70.11% of Python3 online submissions for Power of Two.
#Memory Usage: 13.3 MB, less than 6.20% of Python3 online submissions for Power of Two.

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n<0: return False
        
        count =0
        while n:
            n&=n-1
            count += 1
        if count >1 or count == 0: return False
        else: return True
