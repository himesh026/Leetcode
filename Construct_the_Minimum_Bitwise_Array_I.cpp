// Problem: Construct the Minimum Bitwise Array I
// URL: https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/?envType=daily-question&envId=2026-01-20

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        vector<int> ans(nums.size(),-1);

        for(int i=0;i<nums.size();i++){

            for(int j=1;j<nums[i];j++){

                if((j | (j+1)) == nums[i]){
                    ans[i]=j;
                    break;
                }
                else if((j || (j+1)) > nums[i]) break;
            }
        }

        return ans;
    }
};