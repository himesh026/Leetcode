// Problem: Maximum Amount of Money Robot Can Earn
// URL: https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/?envType=daily-question&envId=2026-04-02

class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& coins,int k,vector<vector<vector<int>>>& dp){
        int n=coins.size();
        int m=coins[0].size();

        if(i>=n || j>=m){
            return -1e9;
        }
        if(i==n-1 && j==m-1){
            if(k>=2)
                return coins[i][j];
            else return max(coins[i][j],0);
        }

        if(dp[i][j][k]!=INT_MIN) return dp[i][j][k];

        int ans=-1e9;

        //moving right
        if(k<2 && coins[i][j]<0){
            ans=max(ans,solve(i,j+1,coins,k+1,dp)); // skip this robbery
            
        }
        ans=max(ans,coins[i][j]+solve(i,j+1,coins,k,dp)); //take it 

        //moving down
        if(k<2 && coins[i][j]<0){
            ans=max(ans,solve(i+1,j,coins,k+1,dp)); // skip it
            
        }
        ans=max(ans,coins[i][j]+solve(i+1,j,coins,k,dp)); // take it


        return dp[i][j][k] = ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size();
        int m=coins[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
        int ans=solve(0,0,coins,0,dp);
        return ans;
    }
};