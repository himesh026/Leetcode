// Problem: Minimum Removals to Balance Array
// URL: https://leetcode.com/problems/minimum-removals-to-balance-array/?envType=daily-question&envId=2026-03-13

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        
        int ans=INT_MAX;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int j=0;
        for(int i=0;i<n;i++){
            while(j<n && nums[j]<=(long long)nums[i]*k){
                j++;
            }
            ans=min(ans,n-(j-i)); 
        }

        return ans;
    }
};