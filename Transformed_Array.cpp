// Problem: Transformed Array
// URL: https://leetcode.com/problems/transformed-array/?envType=daily-question&envId=2026-02-05

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result(nums.size(),0);
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                result[i]=nums[i];
            }
            else{
                result[i]=nums[((i+nums[i])%n+n)%n];
            }

        }

        return result;
    }
};