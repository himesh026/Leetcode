// Problem: Count Number of Maximum Bitwise-OR Subsets
// URL: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/?envType=daily-question&envId=2025-07-28

class Solution {
public:
    int f(int i,int target,int currOr,vector<int> &nums){

        if(i>=nums.size()){
            if(currOr==target) return 1;
            else return 0;
        }
        int take=f(i+1,target,currOr|nums[i],nums);

        int notTake=f(i+1,target,currOr,nums);

        return take+notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        
        int maxiOr=0;// as or is always increasing , it will be the or of entire array
        int n=nums.size();

        for(int i=0;i<n;i++){
            maxiOr|=nums[i];
        }
        return f(0,maxiOr,0,nums);
    }
};