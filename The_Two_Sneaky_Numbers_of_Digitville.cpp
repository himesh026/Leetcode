// Problem: The Two Sneaky Numbers of Digitville
// URL: https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/?envType=daily-question&envId=2025-10-31

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        vector<int> ans;

        for(auto it:freq){
            if(it.second==2){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};