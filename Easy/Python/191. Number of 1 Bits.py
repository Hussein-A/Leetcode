#Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).

#Runtime: 24 ms, faster than 55.71% of Python online submissions for Number of 1 Bits.
#Memory Usage: 11.8 MB, less than 5.10% of Python online submissions for Number of 1 Bits.


class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 0
        while n:
            n &= n-1
            count +=1
        return count
        
