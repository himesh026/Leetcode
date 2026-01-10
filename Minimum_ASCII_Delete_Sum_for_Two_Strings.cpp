// Problem: Minimum ASCII Delete Sum for Two Strings
// URL: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/?envType=daily-question&envId=2026-01-10

class Solution {
public:
    //fxn to find largest ascii sum lcs
    int f(int i,int j,string &s1, string &s2,vector<vector<int> > &dp){

        if(i<0 ||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            return dp[i][j] = int(s1[i])+f(i-1,j-1,s1,s2,dp);
        }

        return dp[i][j] = max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int> > dp(n,vector<int>(m,-1));
        //dp[i][j]=maximum ascii sum of lcs till i , j

        int totalAscii=0;
        for(int i=0;i<n;i++){
            totalAscii+=int(s1[i]);
        }
        for(int j=0;j<m;j++){
            totalAscii+=int(s2[j]);
        }

        return totalAscii-2*f(n-1,m-1,s1,s2,dp);
    }
};