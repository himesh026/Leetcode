// Problem: Maximum Total Subarray Value I
// URL: https://leetcode.com/problems/maximum-total-subarray-value-i/?envType=daily-question&envId=2026-06-09

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        int maxiElem=*max_element(nums.begin(),nums.end());
        int miniElem=*min_element(nums.begin(),nums.end());


        return (long long)(maxiElem-miniElem)*k;
        
    }
};

//apne ko k subarry select krni h 
//ek subarray ki value h => maxElem of subarray - miniElem of subarray
// To puri array hi slect krlo k times :)