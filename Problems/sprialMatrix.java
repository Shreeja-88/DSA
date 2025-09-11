// question -> https://leetcode.com/problems/spiral-matrix/description/
/*
Given an m x n matrix, return all elements of the matrix in spiral order.
Example 1: Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
           Output: [1,2,3,6,9,8,7,4,5]
*/

// Time Complexity : O(m*n) where m is number of rows and n is number of columns
// Space Complexity : O(1) no extra space used

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<Integer>();
        int m = matrix.length; //row 
        int n = matrix[0].length; //column
        int rowStart = 0;
        int rowEnd = m-1;
        int colStart = 0;
        int colEnd = n-1;

        //spiral order matrix
        while(rowStart <= rowEnd && colStart <= colEnd) {
            //1. Traverse right
            for(int col=colStart; col<=colEnd; col++) {
                result.add(matrix[rowStart][col]);
            }
            rowStart++;

            //2. Traverse Down 
            for(int row=rowStart; row<=rowEnd; row++) {
                result.add(matrix[row][colEnd]);
            }
            colEnd--;

            //3. Traverse Left 
            if(rowStart<= rowEnd){
                for(int col=colEnd; col>=colStart; col--) {
                    result.add(matrix[rowEnd][col]);
                }
                rowEnd--;
            }

            //4. Traverse Up
            if (colStart <= colEnd) {
                for(int row=rowEnd; row>=rowStart; row--) {
                    result.add(matrix[row][colStart]);
                }
                colStart++;
            }

        }
        return result;
    }
}