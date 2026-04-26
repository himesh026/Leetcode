// Problem: Detect Cycles in 2D Grid
// URL: https://leetcode.com/problems/detect-cycles-in-2d-grid/?envType=daily-question&envId=2026-04-26

class Solution {
public:
    bool dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& isVis,vector<int> &rowd,vector<int> &colmd,int parentI,int parentJ){
        int m=grid.size();
        int n=grid[0].size();
        isVis[i][j]=1;

        for(int k=0;k<4;k++){
            int ni=i+rowd[k];
            int nj=j+colmd[k];
            if(ni>=0 && ni<m && nj>=0 && nj<n && grid[i][j]==grid[ni][nj]){
                if(isVis[ni][nj]==0){
                    if(dfs(ni,nj,grid,isVis,rowd,colmd,i,j)) return true;
                }
                else{
                    if(ni!=parentI || nj!=parentJ) {
                        return true;
                    }
                }
            }
            
        }

        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int> > isVis(m,vector<int>(n,0));
        vector<int> rowd={-1,0,1,0};
        vector<int> colmd={0,1,0,-1};
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                if(isVis[i][j]==0){
                    if(dfs(i,j,grid,isVis,rowd,colmd,-1,-1)) return true;
                }
            }
        }

        return false;
    }
};


// simply dfs from each unvisted cell if we found a cycel the return true
//  for cycle => node is visted but not parent of current node=> cycle detected