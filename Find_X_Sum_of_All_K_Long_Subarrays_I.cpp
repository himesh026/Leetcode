// Problem: Find X-Sum of All K-Long Subarrays I
// URL: https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/?envType=daily-question&envId=2025-11-04

class Solution {
public:
    void solve(map<int,int> &freq,vector<int>&nums,vector<int>&ans,int left,int k,int x){
        if(freq.size()<x){
            ans[left]=accumulate(nums.begin()+left,nums.begin()+left+k,0);
        }
        else{
            //find x most frequent
            vector<pair<int,int> > arr;
            for(auto it:freq){
                arr.push_back({it.second,it.first});
            }
            sort(arr.rbegin(),arr.rend());
            for(int i=0;i<x;i++){
                ans[left]+=arr[i].first*arr[i].second;
            }
            
        }
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        
        vector<int> ans(nums.size()-k+1);
        int left=0;
        int right=k-1;
        map<int,int> freq;
        for(int i=0;i<k;i++){
            freq[nums[i]]++;
        }

        while(right<nums.size()){
            solve(freq,nums,ans,left,k,x);
            freq[nums[left]]--;
            left++;
            right++;
            if(right<nums.size()) freq[nums[right]]++;
        }

        return ans;
    }
};