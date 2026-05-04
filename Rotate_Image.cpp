// Problem: Rotate Image
// URL: https://leetcode.com/problems/rotate-image/?envType=daily-question&envId=2026-05-04

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n=matrix.size(); // square matrix

        //take in place transpose

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //now reverse every row;
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }

        return;
    }
};