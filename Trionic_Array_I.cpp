// Problem: Trionic Array I
// URL: https://leetcode.com/problems/trionic-array-i/?envType=daily-question&envId=2026-02-03

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        
        int p=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                p=i;
            }
            else if(nums[i]==nums[i-1]) return false;
            else break;
        }
        if(p==-1) return false;

        int q=-1;

        for(int i=p;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                q=i+1;
            }
            else if(nums[i]==nums[i+1]) return false;
            else break;
        }

        if(q==-1 || q==nums.size()-1) return false;

        for(int i=q;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]) continue;
            else return false;
        }

        return true;
    }
};