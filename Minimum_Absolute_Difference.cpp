// Problem: Minimum Absolute Difference
// URL: https://leetcode.com/problems/minimum-absolute-difference/?envType=daily-question&envId=2026-01-26

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minabsdiff=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=1;i<arr.size();i++){
            minabsdiff=min(minabsdiff,arr[i]-arr[i-1]);
        }

        vector<vector<int>>ans;
        for(int i=1;i<arr.size();i++){
            if((arr[i]-arr[i-1])==minabsdiff){
                ans.push_back({arr[i-1],arr[i]});
            }

        }

        return ans;
    }
};