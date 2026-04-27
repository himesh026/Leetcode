// Problem: Check if There is a Valid Path in a Grid
// URL: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/?envType=daily-question&envId=2026-04-27

class Solution {
public:
    bool dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& isVis,vector<vector<set<int>>>& dirn){

        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n) return false;
        if(i==m-1 && j==n-1){
            isVis[i][j]=true;
            return true;
        }
        isVis[i][j]=true;
        int value=grid[i][j];

        if(value==1){
            if(j+1<n && isVis[i][j+1]==false && dirn[value][1].find(grid[i][j+1])!=dirn[value][1].end()){
                if(dfs(i,j+1,grid,isVis,dirn)) return true;
            }
            if(j-1>=0 && isVis[i][j-1]==false &&  dirn[value][3].find(grid[i][j-1])!=dirn[value][3].end()){
                if(dfs(i,j-1,grid,isVis,dirn)) return true;
            }
        }
        if(value==2){
            if(i-1>=0 && isVis[i-1][j]==false &&  dirn[value][0].find(grid[i-1][j])!=dirn[value][0].end()){
                if(dfs(i-1,j,grid,isVis,dirn)) return true;
            }
            if(i+1<m && isVis[i+1][j]==false &&  dirn[value][2].find(grid[i+1][j])!=dirn[value][2].end()){
                if(dfs(i+1,j,grid,isVis,dirn)) return true;
            }
        }
        if(value==3){
            if(j-1>=0 && isVis[i][j-1]==false &&  dirn[value][3].find(grid[i][j-1])!=dirn[value][3].end()){
                if(dfs(i,j-1,grid,isVis,dirn)) return true;
            }
            if(i+1<m && isVis[i+1][j]==false &&  dirn[value][2].find(grid[i+1][j])!=dirn[value][2].end()){
                if(dfs(i+1,j,grid,isVis,dirn)) return true;
            }
        }
        if(value==4){
            if(j+1<n && isVis[i][j+1]==false &&  dirn[value][1].find(grid[i][j+1])!=dirn[value][1].end()){
                if(dfs(i,j+1,grid,isVis,dirn)) return true;
            }
            if(i+1<m && isVis[i+1][j]==false &&  dirn[value][2].find(grid[i+1][j])!=dirn[value][2].end()){
                if(dfs(i+1,j,grid,isVis,dirn)) return true;
            }
        }
        if(value==5){
            if(i-1>=0 && isVis[i-1][j]==false &&  dirn[value][0].find(grid[i-1][j])!=dirn[value][0].end()){
                if(dfs(i-1,j,grid,isVis,dirn)) return true;
            }
            if(j-1>=0 && isVis[i][j-1]==false &&  dirn[value][3].find(grid[i][j-1])!=dirn[value][3].end()){
                if(dfs(i,j-1,grid,isVis,dirn)) return true;
            }
        }
        if(value==6){
            if(i-1>=0 && isVis[i-1][j]==false &&  dirn[value][0].find(grid[i-1][j])!=dirn[value][0].end()){
                if(dfs(i-1,j,grid,isVis,dirn)) return true;
            }
            if(j+1<n &&  isVis[i][j+1]==false && dirn[value][1].find(grid[i][j+1])!=dirn[value][1].end()){
                if(dfs(i,j+1,grid,isVis,dirn)) return true;
            }
        }

        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<set<int>>> dirn(7,vector<set<int>>(4));
        for(int i=1;i<=6;i++){
            if(i==1){
                dirn[i][1]={3,1};
                dirn[i][3]={1,4};
            }
            else if(i==2){
                dirn[i][0]={3,4,2};
                dirn[i][2]={5,6,2};

            }
            else if(i==3){
                dirn[i][2]={2,5,6};
                dirn[i][3]={1,4,6};

            }
            else if(i==4){
                dirn[i][1]={1,5,3};
                dirn[i][2]={2,6,5};

            }
            else if(i==5){
                dirn[i][0]={2,3,4};
                dirn[i][3]={1,6,4};

            }
            else if(i==6){
                dirn[i][0]={2,3,4};
                dirn[i][1]={1,3,5};

            }
        }
        vector<vector<bool>> isVis(m,vector<bool>(n,false));

        if(dfs(0,0,grid,isVis,dirn)) return true;

        return isVis[m-1][n-1];
    }
};

//simply pta kiya ki grid[i][j]=value , value k according up,down,left,right pr kha kha ja skte h or fir dfs lga diya 