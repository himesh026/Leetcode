// Problem: Construct Product Matrix
// URL: https://leetcode.com/problems/construct-product-matrix/?envType=daily-question&envId=2026-03-24

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mod=12345;
        vector<int> nums;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nums.push_back(grid[i][j]);
            }
        }
        vector<long long> prefixPrd(n*m,1);
        vector<long long> suffixPrd(n*m,1);
        prefixPrd[0]=1;
        for(int i=1;i<n*m;i++){
            prefixPrd[i]=(prefixPrd[i-1]*nums[i-1])%mod;
        }
        suffixPrd[n*m-1]=1;
        for(int i=n*m-2;i>=0;i--){
            suffixPrd[i]=(suffixPrd[i+1]*nums[i+1])%mod;
        }
        vector<vector<int>> ans(n,vector<int>(m,1));

        int row=0;
        int colm=0;
        int cnt=1;

        for(int i=0;i<n*m;i++){
            ans[row][colm]=(prefixPrd[i]*suffixPrd[i])%mod;
            colm++;
            if((i+1)%m==0){
                colm=0;
                row++;
            }
        }
        return ans;
    }
};