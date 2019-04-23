#There is a robot starting at position (0, 0), the origin, on a 2D plane. Given a sequence of its moves, judge if this robot ends up at 
#(0, 0) after it completes its moves. The move sequence is represented by a string, and the character moves[i] represents its ith move. 
#Valid moves are R (right), L (left), U (up), and D (down). If the robot returns to the origin after it finishes all of its moves, return 
#true. Otherwise, return false.
#Note: The way that the robot is "facing" is irrelevant. "R" will always make the robot move to the right once, "L" will always make it 
#move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.

#Runtime: 84 ms beats 18.80 % of python3 submissions.
#MEM: 13.1 MB
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        x= y = 0
        for c in moves:
            if c == 'U':
                y+=1
            elif c == 'D':
                y-=1
            elif c == 'L':
                x-=1
            elif c == 'R':
                x+= 1
        return x == y == 0
