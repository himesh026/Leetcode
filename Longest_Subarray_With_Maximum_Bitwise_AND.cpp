// Problem: Longest Subarray With Maximum Bitwise AND
// URL: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/?envType=daily-question&envId=2025-07-30

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElem=*max_element(nums.begin(),nums.end());
        int maxAnd=maxElem; // maximum And , array k maximum element k equal hi hoga
        int ans=0;
        int left=0,right=0;
        while(left<nums.size()){
            if(nums[right]==maxElem){
                while(right<nums.size() && nums[right]==maxElem) right++;
                ans=max(ans,right-left);
                left=right;
            }
            else{
                right++;
                left++;
            }
            
            
        }

        return ans;
    }
};