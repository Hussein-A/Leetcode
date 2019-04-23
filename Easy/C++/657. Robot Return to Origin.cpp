/*
There is a robot starting at position (0, 0), the origin, on a 2D plane. 
Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.
The move sequence is represented by a string, and the character moves[i] represents its ith move. 
Valid moves are R (right), L (left), U (up), and D (down). If the robot returns to the origin after it finishes all of its moves, return true. 
Otherwise, return false. Note: The way that the robot is "facing" is irrelevant. "R" will always make the robot move to the right once, "L" will always make it move left, etc. 
Also, assume that the magnitude of the robot's movement is the same for each move.

Runtime beats 27.50 % of cpp submissions.
Memory usage beats 99.22 % of cpp submissions.
*/

class Solution {
public:
#define up 0
#define down 1
#define left 2
#define right 3

	bool judgeCircle(string moves) {
		vector<int> moves_count(4);
		for (char& ch : moves) {
			switch (ch) {
			case 'U':
				++moves_count[up];
				break;
			case 'D':
				--moves_count[down];
				break;
			case 'L':
				++moves_count[left];
				break;
			case 'R':
				--moves_count[right];
				break;
			}
		}
		int sum1 = accumulate(moves_count.begin(), moves_count.begin() + 2, 0);
		int sum2 = accumulate(moves_count.begin() + 2, moves_count.end(), 0);
		if (sum1 == 0 && sum2 == 0) return true;
		else return false;

	}
};