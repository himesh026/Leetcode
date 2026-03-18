// Problem: Count Submatrices with Top-Left Element and Sum Less Than k
// URL: https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/?envType=daily-question&envId=2026-03-18

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                grid[i][j]+=grid[i][j-1];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]+=grid[i-1][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<grid[i][j]<<endl;
                if(grid[i][j]<=k) ans++;
            }
            cout<<endl;
        }

        return ans;
    }
};