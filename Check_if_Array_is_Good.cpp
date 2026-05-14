// Problem: Check if Array is Good
// URL: https://leetcode.com/problems/check-if-array-is-good/?envType=daily-question&envId=2026-05-14

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        int base=n-1;
        sort(nums.begin(),nums.end());

        for(int i=0;i<base;i++){
            if(nums[i]!=i+1) return false;
        }



        return nums[base]==base; 
    }
};