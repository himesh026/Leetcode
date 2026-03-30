// Problem: Sum of Sortable Integers
// URL: https://leetcode.com/problems/sum-of-sortable-integers/

class Solution {
public:
    bool solve(vector<int>&nums,int k){
        int n=nums.size();
        int prevMax=-1;
        for(int i=0;i<n;i+=k){
            int currSubarrayMax=nums[i],currSubarrayMin=nums[i];
            int breakpoints=0;
            for(int j=i;j<i+k-1;j++){
                if(nums[j]>nums[j+1]) breakpoints++;
                currSubarrayMax=max(currSubarrayMax,nums[j]);
                currSubarrayMin=min(currSubarrayMin,nums[j]);
            }
            currSubarrayMax=max(currSubarrayMax,nums[i+k-1]);
            currSubarrayMin=min(currSubarrayMin,nums[i+k-1]);
            if(breakpoints==0){
                //already sorted subaaray no need to do anything check further subaarays
            }
            else if(breakpoints==1){
                if(nums[i]<nums[i+k-1]) return false;
            }
            else return false;

            if(prevMax>currSubarrayMin){
                return false;
            }

            prevMax=currSubarrayMax;
        }

        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        int ans=0; // sum of all sortable k
        for(int k=1;k<=n;k++){
            if(n%k!=0) continue;
            else if(solve(nums,k)){
                ans+=k;
            }
        }

        return ans;
    }
};