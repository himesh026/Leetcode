// Problem: Paths in Matrix Whose Sum Is Divisible by K
// URL: https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/?envType=daily-question&envId=2025-11-26

class Solution {
public:
    int MOD=1e9+7;
    int f(int i,int j,vector<vector<int>>& grid, int k,int value,vector<vector<vector<int> > > &dp){
        int n=grid.size();
        int m=grid[0].size();

        if(i>=n || j>=m) return 0;

        if(i==n-1 && j==m-1){

            if((grid[i][j]+value)%k==0) return 1;
            else return 0;
        }

        if(dp[i][j][value]!=-1) return dp[i][j][value];

        int down=f(i+1,j,grid,k,(value+grid[i][j])%k,dp);
        int right=f(i,j+1,grid,k,(value+grid[i][j])%k,dp);

        return dp[i][j][value] = (down+right)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<vector<int> > > dp(n,vector<vector<int>>(m,vector<int>(51,-1)));

        int ans=f(0,0,grid,k,0,dp);

        return ans;
    }
};


// (x1+x2+x3+x4)%k=y
//(x1+x2+x3+x4+x5)%k=> (x1+x2+x3+x4)%k + x5%k => y + x5%k 
// so no need to sum up , we only need remainder 