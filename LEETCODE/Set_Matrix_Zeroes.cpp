/*
Approach:- We use the first row and first column of the matrix to keep a track whether there is a zero in a particular row or column or not when we encounter a zero lets say at the cell (i,j) then we make matrix[i][0]=0 and matrix[0][j]= 0 indicating that there is a zero in cell row i and column j. After traversing the entire matrix and marking all the zeros in the first row and first column respectively (when needed) we traverse the first row and first column and make that row and column zero that contains a zero in that cell (eg:- if cell (i,0) is zero we make the entire row i as zero and if cell (0,j) is zero we make the entire column j as zero). However we have to take into consideration for the edge cases where the firstRow or the firstColumn contains a zero as we change the firstRow and firstColumn of the matrix and hence there may be a chance that we didn't perform operation properly for the firstRow and firstColumn. Hence we mark the zero in the firstRow and firstColumn by using two boolean variables and after we have finished marking the zeros for the remaining matrix (matrix except the first row and first column) we check the boolean variables value if they are true we mark the first row and the first column with zero accordingly from the boolean variable being true or false;
*/

// YT Link:- https://www.youtube.com/watch?v=3ylBTHCiihw&list=PLjeQ9Mb66hM33kyoJjJbHf72Rb0G70Sae&index=30
// Problem Link:- https://leetcode.com/problems/set-matrix-zeroes/description/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool firstRow = false, firstCol = false;
        // check whether there is a zero in the first row
        for (int i = 0; i < n; i++)
            if (matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        // check whether there is a zero in the first column
        for (int j = 0; j < m; j++)
            if (matrix[0][j] == 0) {
                firstRow = true;
                break;
            }
        // check for the zeros in the remaining matrix except the first row and first column
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // mark the zeros if found to the remaining matrix (except the first row and the first column)
        for (int j = 1; j < m; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < n; i++)
                    matrix[i][j] = 0;
            }
        }
        for (int i = 1; i < n; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < m; j++)
                    matrix[i][j] = 0;
            }
        }
        // if there is a zero in the firstRow then mark the firstRow as zero
        if (firstRow)
            for (int j = 0; j < m; j++)
                matrix[0][j] = 0;
        // if there is a zero in the firstColumn then mark the firstColumn as zero
        if (firstCol)
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
    }
};