// Problem: Maximum Erasure Value
// URL: https://leetcode.com/problems/maximum-erasure-value/?envType=daily-question&envId=2025-07-22

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> hash;
        int sum=0;
        int left=0;
        int right=0;
        int n=nums.size();
        int ans=0;

        while(right<n){
            if(hash.find(nums[right])!=hash.end()){
                //shrink window jha repeated value phle aa rkhi uske ek aage tk
                while(left<=hash[nums[right]]){
                    sum-=nums[left];
                    hash.erase(nums[left]);
                    left++;
                }
            }
            //expand window 
            hash[nums[right]]=right;
            sum+=nums[right];
            ans=max(ans,sum);
            right++;

        }

        return ans;
    }
};