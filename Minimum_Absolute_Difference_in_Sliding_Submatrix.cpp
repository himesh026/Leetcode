// Problem: Minimum Absolute Difference in Sliding Submatrix
// URL: https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/?envType=daily-question&envId=2026-03-20

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {

        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n-k+1,vector<int>(m-k+1,0));
        if(k==1) return ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // top left corenr grid[i][j] 
                //kxk
                if(i+k>n || j+k>m) break;
                vector<int> temp;
                for(int l=i;l<i+k;l++){
                    for(int r=j;r<j+k;r++){
                        temp.push_back(grid[l][r]);
                    }
                }
                sort(temp.begin(),temp.end());
                int curr=INT_MAX;
                for(int p=1;p<temp.size();p++){
                    if(temp[p]==temp[p-1]) continue;
                    curr=min(curr,temp[p]-temp[p-1]);
                }
                if(curr!=INT_MAX) ans[i][j]=curr;

            }
        }
        return ans;
    }
};