#You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  
#Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.
#The letters in J are guaranteed distinct, and all characters in J and S are letters. 
#Letters are case sensitive, so "a" is considered a different type of stone from "A".

# Runtime beats 70.33 % of python3 submissions
# MEM: 13.2 MB

class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        sum = 0
        for char in J:
            sum = sum + S.count( char)
        
        return sum
