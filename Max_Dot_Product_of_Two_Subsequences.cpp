// Problem: Max Dot Product of Two Subsequences
// URL: https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/?envType=daily-question&envId=2026-01-08

class Solution {
public:
    int f(int i,int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int> > &dp){

        if(i<0 || j<0) return -1e9;

        if(dp[i][j]!=-1) return dp[i][j];

        //all possible
        int a=f(i-1,j-1,nums1,nums2,dp); // skip last elem of both
        int b=f(i-1,j-1,nums1,nums2,dp)+nums1[i]*nums2[j]; // take last elem of both
        int c=f(i-1,j,nums1,nums2,dp); //skip last elem in nums1
        int d=f(i,j-1,nums1,nums2,dp); // skip last elem in nums2;
        int e=nums1[i]*nums2[j]; // only last elem

        return dp[i][j] = max({a,b,c,d,e});

    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int> > dp(nums1.size(),vector<int>(nums2.size(),-1));

        return f(nums1.size()-1,nums2.size()-1,nums1,nums2,dp);
    }
};

//longest common subseqence variant