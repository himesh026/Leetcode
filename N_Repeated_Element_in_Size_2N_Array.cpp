// Problem: N-Repeated Element in Size 2N Array
// URL: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/?envType=daily-question&envId=2026-01-02

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        int N=nums.size();
        int n=N/2;

        unordered_map<int,int> freq;

        for(int i=0;i<N;i++){
            freq[nums[i]]++;
        }

        for(auto it:freq){
            if(it.second==n) return it.first;
        }

        return -1;
    }
};