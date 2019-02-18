/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row;
        vector<int> col;
        for(int i  = 0; i < matrix.size() ; i++){
            for (int  j = 0; j < matrix[i].size() ; j++){
                if (matrix[i][j] == 0){
                     row.push_back(i);
                     col.push_back(j);
                }
            }
        }

        matrixrow(row, matrix);
        matrixcol(col, matrix);
    }
    
    void matrixrow(vector<int> &row , vector <vector<int> > &matrix){
        for (int z = 0 ; z< row.size(); z++){
            for (int j = 0; j < matrix[row[z]].size(); j++){
                matrix[row[z]][j] = 0;
            }            
        }

    }
    
    void matrixcol(vector<int> &col , vector <vector<int> > &matrix){
        for (int z =0; z< col.size(); z++){
            for (int i = 0; i < matrix.size(); i++){
                matrix[i][col[z]] = 0;
            }
        }
    }
};
