// Problem: Maximum Unique Subarray Sum After Deletion
// URL: https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/?envType=daily-question&envId=2025-07-25

class Solution {
public:
    int maxSum(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0]; // mentioned that ithout making it empty . we cant return 0 in case of [-ve value]
        }
        vector<int> arr;
        unordered_set<int> st;
        int cntnegative=0;
        int maxiNegative=INT_MIN;
        int cntZero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                cntnegative++;
                maxiNegative=max(maxiNegative,nums[i]);
                continue;

            }
            else if(nums[i]==0) cntZero++;
            else if(st.find(nums[i])!=st.end()) continue;
            else{
                arr.push_back(nums[i]);
                st.insert(nums[i]);
            }
        }
        if(cntnegative==nums.size()){
            //all are -ve
            return maxiNegative;
        }
        if(cntnegative+cntZero==nums.size()){
            //sirf -ve and zero h
            return 0;
        }
        int ans=accumulate(arr.begin(),arr.end(),0);

        return ans;
    }
};