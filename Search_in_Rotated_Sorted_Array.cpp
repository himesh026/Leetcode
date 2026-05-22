// Problem: Search in Rotated Sorted Array
// URL: https://leetcode.com/problems/search-in-rotated-sorted-array/?envType=daily-question&envId=2026-05-22

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n=nums.size();
        //for log(n) time complexity we have to do binary search
//         One side (left or right) will always remain sorted.
//          Check whether the target lies inside the sorted half.
        
        int left=0;
        int right=n-1;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(nums[mid]==target) return mid;

            //agr left side sorted h
            if(nums[left]<=nums[mid]){
                if(target>=nums[left] && target<=nums[mid]){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            else{
                //right sorted h
                if(target>=nums[mid] && target<=nums[right]){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
        }

        return -1;
    }
};