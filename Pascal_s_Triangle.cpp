// Problem: Pascal's Triangle
// URL: https://leetcode.com/problems/pascals-triangle/?envType=daily-question&envId=2025-08-01

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});

        for(int i=1;i<numRows;i++){
            vector<int> temp(i+1,0); // ith(0 indexing) row have i+1 length 
            temp[0]=1; //first elemnt always 1
            for(int j=1;j<i;j++){
                temp[j]=ans[i-1][j]+ans[i-1][j-1];
            }
            temp[i]=1; //last elemnet always 1
            ans.push_back(temp);
        }

        return ans;
    }
};