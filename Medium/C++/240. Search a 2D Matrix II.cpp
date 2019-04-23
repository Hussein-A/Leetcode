/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
	Integers in each row are sorted in ascending from left to right.
	Integers in each column are sorted in ascending from top to bottom.

Runtime: 64 ms, faster than 97.55% of C++ online submissions for Search a 2D Matrix II.
Memory Usage: 12.8 MB, less than 64.53% of C++ online submissions for Search a 2D Matrix II.
*/

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		const int& row_size = matrix.size();
		if (row_size == 0) return false;
		const int& col_size = matrix[0].size();
		if (col_size == 0) return false;


		int row = row_size - 1;
		int col = 0;
		int* curr_val = &matrix[row][col];
		while (row >= 0 && col < col_size) {
			curr_val = &matrix[row][col];
			if (*curr_val == target) return true;
			else if (target > *curr_val) ++col;
			else --row;
		}
		return false;

	}
};