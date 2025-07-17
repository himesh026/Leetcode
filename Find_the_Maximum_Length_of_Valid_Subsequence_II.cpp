// Problem: Find the Maximum Length of Valid Subsequence II
// URL: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/?envType=daily-question&envId=2025-07-17

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int> > dp(k,vector<int>(k,0));
        int ans=0;
        for(auto x:nums){
            int currMod=x%k;
            for(int prevMod=0;prevMod<k;prevMod++){
                dp[prevMod][currMod]=dp[currMod][prevMod]+1;
                ans=max(ans,dp[prevMod][currMod]);
            }
        }
        // for(int i=0;i<k;i++){
        //     for(int j=0;j<k;j++){
        //         cout<<dp[i][j]<<" , ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};