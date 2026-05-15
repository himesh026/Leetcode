// Problem: Find Minimum in Rotated Sorted Array
// URL: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/?envType=daily-question&envId=2026-05-15

class Solution {
public:
    int findMin(vector<int>& nums) {

        int l=0,r=nums.size()-1,mid;
        while(l<r){

          mid=(l+r)/2;

          if(nums[mid]<nums[r]){
            r=mid;
          }
          else{
            l=mid+1;
          }
        }

        return nums[l];
    }
};

// O(log n) time.