// Problem: Separate the Digits in an Array
// URL: https://leetcode.com/problems/separate-the-digits-in-an-array/?envType=daily-question&envId=2026-05-11

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            string s=to_string(nums[i]);
            for(int j=0;j<s.size();j++){
                ans.push_back(s[j]-'0');
            }
        }

        return ans;
    }
};