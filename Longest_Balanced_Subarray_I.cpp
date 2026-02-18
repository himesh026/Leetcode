// Problem: Longest Balanced Subarray I
// URL: https://leetcode.com/problems/longest-balanced-subarray-i/?envType=daily-question&envId=2026-02-18

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        for(int i=0;i<n;i++){
            unordered_set<int> even;
            unordered_set<int> odd;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0) even.insert(nums[j]);
                else odd.insert(nums[j]);

                if(even.size()==odd.size()){
                    ans=max(ans,j-i+1);
                }
            }
        }

        return ans;
    }
};