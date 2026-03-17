// Problem: Largest Submatrix With Rearrangements
// URL: https://leetcode.com/problems/largest-submatrix-with-rearrangements/?envType=daily-question&envId=2026-03-17

class Solution {
public:

    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    continue; 
                }
                matrix[i][j]+=matrix[i-1][j];
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            vector<int> heights=matrix[i];
            sort(heights.begin(),heights.end());
            for(int j=0;j<n;j++){
                ans=max(ans,(n-j)*heights[j]);
            }
        }

        return ans;
    }
};