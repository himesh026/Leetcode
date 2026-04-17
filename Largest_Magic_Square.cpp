// Problem: Largest Magic Square
// URL: https://leetcode.com/problems/largest-magic-square/?envType=daily-question&envId=2026-04-17

class Solution {
public:
    bool solve(int i,int j,int k,vector<vector<int>>& grid){
        unordered_set<int> st;

        //row sum
        for(int x=i;x<i+k;x++){
            int rowSum=0;
            for(int y=j;y<j+k;y++){
                rowSum+=grid[x][y];

            }
            st.insert(rowSum);
            rowSum=0;

            if(st.size()>1) return false;
        }
        //diagonal sum
        int d1Sum=0,d2Sum=0;


        for(int t = 0; t < k; t++){
            d1Sum += grid[i + t][j + t];                 // main diagonal
            d2Sum += grid[i + t][j + k - 1 - t];         // anti-diagonal
        }
        st.insert(d1Sum);
        st.insert(d2Sum);
        if(st.size()>1) return false;
        //colm sum
        for(int y=j;y<j+k;y++){
            int colmSum=0;
            for(int x=i;x<i+k;x++){
                colmSum+=grid[x][y];
            }
            st.insert(colmSum);
            colmSum=0;
            if(st.size()>1) return false;
        }
        if(st.size()>1) return false;

        return true;

    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int k=min(n,m);

        for(;k>=1;k--){

            for(int i=0;i<n;i++){
                if(i+k>n) continue;
                for(int j=0;j<m;j++){
                    if(j+k>m) continue;
                    if(solve(i,j,k,grid)) return k;
                }
            }
        }

        return 1;
    }
};

//thought process
// bruteforce simply check alll k size square return largest k which satisfy the condition where all row sum=all colm sums=both diagonals sum