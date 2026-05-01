// Problem: Rotate Function
// URL: https://leetcode.com/problems/rotate-function/?envType=daily-question&envId=2026-05-01

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();

        int numSum=0;

        int f=0; 

        for(int i=0;i<n;i++){
            numSum+=nums[i];
            f=f+(i*nums[i]);
        }

        int ans=f;

        for(int i=1;i<n;i++){
            f=f+numSum-n*nums[n-i];
            ans=max(ans,f);
        }

        return ans;
    }
};

// on paper clalculate f0,f1,f2 do f1-f0 , f2-f1 you will find a pattern 