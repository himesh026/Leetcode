// Problem: Maximum Path Score in a Grid
// URL: https://leetcode.com/problems/maximum-path-score-in-a-grid/?envType=daily-question&envId=2026-04-30

class Solution {
public:
    int solve(int i,int j,int k,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        int m=grid.size();
        int n=grid[0].size();

        if(i>=m || j>=n) return -1e9;
        if(k<0) return -1e9;
        if(i==m-1 && j==n-1){
            if(k>0){
                if(grid[i][j]==0) return 0;
                else if(grid[i][j]==1){
                    k--;
                    return 1;
                }
                else{
                    k--;
                    return 2;
                }
            }
            else if(k==0){
                if(grid[i][j]==0) return 0;
                else return -1e9;
            }
            
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int value=grid[i][j];
        int right=-1e9;
        int down=-1e9;
        if(value==0){
            //right
            right=0+solve(i,j+1,k,grid,dp);
            //down
            down=0+solve(i+1,j,k,grid,dp);

        }
        else if(value==1){
            //right
            right=1+solve(i,j+1,k-1,grid,dp);
            //down
            down=1+solve(i+1,j,k-1,grid,dp);

        }
        else{
            //right
            right=2+solve(i,j+1,k-1,grid,dp);
            //down
            down=2+solve(i+1,j,k-1,grid,dp);

        }

        return dp[i][j][k]=max(right,down);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int ans=solve(0,0,k,grid,dp);

        return ans>=0? ans:-1;
    }
};

//problem is similar to knapsack here we want to start from (0,0)->(m-1,n-1) but we have only k money to spend to reach destination , so 3d dp work easily 