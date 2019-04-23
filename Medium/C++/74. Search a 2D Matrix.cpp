/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
	Integers in each row are sorted from left to right.
	The first integer of each row is greater than the last integer of the previous row.

Runtime: 12 ms, faster than 98.49% of C++ online submissions for Search a 2D Matrix.
Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Search a 2D Matrix.
*/

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		const int&  row_size = matrix.size();
		if (row_size == 0) return false;
		const int&  col_size = matrix[0].size();
		if (col_size == 0) return false;


		int row_count = 0;
		vector<int> curr_row = matrix[row_count];
		while (row_count < row_size) {
			curr_row = matrix[row_count];
			if (target <= curr_row[col_size - 1]) return binary_search(curr_row.begin(), curr_row.end(), target);
			++row_count;
		}
		return false;
	}
};