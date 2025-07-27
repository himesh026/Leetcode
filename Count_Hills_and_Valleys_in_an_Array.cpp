// Problem: Count Hills and Valleys in an Array
// URL: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/?envType=daily-question&envId=2025-07-27

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
        int hills=0;
        int valley=0;

        for(int i=0;i<nums.size();i++){
            if(i-1>=0 && nums[i]==nums[i-1]) continue;
            int prev=-1e9;
            for(int j=i-1;j>=0;j--){
                if(nums[j]!=nums[i]){
                    prev=nums[j];
                    break;
                }
            }
            int next=-1e9;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]!=nums[i]){
                    next=nums[j];
                    break;
                }
            }
 
            if(prev==-1e9 || next==-1e9) continue;
            if(nums[i]>prev && nums[i]>next){
                hills++; 
            }
            if(nums[i]<prev && nums[i]<next){
                valley++; 
            }

        }

        return hills+valley;
    }
};