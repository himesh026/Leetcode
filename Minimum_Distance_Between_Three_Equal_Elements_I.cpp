// Problem: Minimum Distance Between Three Equal Elements I
// URL: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/?envType=daily-question&envId=2026-04-10

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if((nums[i] == nums[j]) && (nums[j] == nums[k]))ans=min(ans,abs(i - j) + abs(j - k) + abs(k - i));
                }
            }
        }

        return (ans==INT_MAX)? -1:ans;
    }
};