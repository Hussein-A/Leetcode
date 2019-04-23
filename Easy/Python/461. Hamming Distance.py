#The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
#Given two integers x and y, calculate the Hamming distance.
# Note: 0 <= x, y < 2^31.

#Runtime: 36 ms, faster than 88.35% of Python3 online submissions for Hamming Distance.
#Memory Usage: 13.4 MB, less than 5.84% of Python3 online submissions for Hamming Distance.

class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        binary = x ^ y
        count = 0
        
        while binary:
            binary &= binary-1
            count +=1
        
        return count
