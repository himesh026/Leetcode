// Problem: Minimum Swaps to Arrange a Binary Grid
// URL: https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/?envType=daily-question&envId=2026-03-02

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size(); // n*n
        vector<int> rightmostone(n,-1);

        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1){
                    rightmostone[i]=j;
                    break;
                }
            }
        }


        int ans=0;

        for(int i=0;i<n;i++){
            int ideal=i;

            if(rightmostone[i]<=ideal) continue;

            int j=i+1;
            while(j<n && rightmostone[j]>ideal) j++;

            if(j==n) return -1;

            while(j>i){
                swap(rightmostone[j],rightmostone[j-1]);
                j--;
                ans++;
            }
        }
        return ans;
    }
};