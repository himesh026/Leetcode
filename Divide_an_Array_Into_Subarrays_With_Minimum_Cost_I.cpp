// Problem: Divide an Array Into Subarrays With Minimum Cost I
// URL: https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/?envType=daily-question&envId=2026-02-01

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans=nums[0];
        priority_queue<int> pq;
        for(int i=nums.size()-1;i>=1;i--){
            pq.push(nums[i]);
            if(pq.size()>2){
                pq.pop();
            }
        }

        while(pq.empty()==false){
            ans+=pq.top();
            pq.pop();
        }

        return ans;
    }
};