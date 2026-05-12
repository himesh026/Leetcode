// Problem: Maximum Number of Jumps to Reach the Last Index
// URL: https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/?envType=daily-question&envId=2026-05-10

class Solution {
public:
    int solve(int i,vector<int>& nums, int target,int n,vector<int>& dp){

        if(i>=n) return -1e9;
        if(i==n-1){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];

        int ans=-1e9;
        for(int j=i+1;j<n;j++){
            if((nums[j]-nums[i])>=-1*target && (nums[j]-nums[i])<=target){
                ans=max(ans,1+solve(j,nums,target,n,dp));
            }
        }

        return dp[i]=ans;
        
    }
    int maximumJumps(vector<int>& nums, int target) {
        
        int n=nums.size();
        vector<int> dp(n,-1);
        int ans=solve(0,nums,target,n,dp);
        return ans<0? -1:ans;
    }
};

//simple approach h ki 0 index se jayenge sare path valid path dekh lengee jo maximum dega vo answer