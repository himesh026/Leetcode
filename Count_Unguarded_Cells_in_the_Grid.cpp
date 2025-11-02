// Problem: Count Unguarded Cells in the Grid
// URL: https://leetcode.com/problems/count-unguarded-cells-in-the-grid/?envType=daily-question&envId=2025-11-02

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<string>> grid(m,vector<string>(n,"0"));

        for(int i=0;i<guards.size();i++){
            grid[guards[i][0]][guards[i][1]]="g";
        }
        for(int i=0;i<walls.size();i++){
            grid[walls[i][0]][walls[i][1]]="w";
        }


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=="w") continue;
                else if(grid[i][j]=="g"){
                    //up
                    for(int k=i-1;k>=0;k--){
                        if(grid[k][j]=="w") break;
                        else if(grid[k][j]=="g") break;
                        else grid[k][j]="1";
                    }
                    //down
                    for(int k=i+1;k<m;k++){
                        if(grid[k][j]=="w") break;
                        else if(grid[k][j]=="g") break;
                        else grid[k][j]="1";
                    }
                    //left
                    for(int k=j-1;k>=0;k--){
                        if(grid[i][k]=="w") break;
                        else if(grid[i][k]=="g") break;
                        else grid[i][k]="1";
                    }
                    //right
                    for(int k=j+1;k<n;k++){
                        if(grid[i][k]=="w") break;
                        else if(grid[i][k]=="g") break;
                        else grid[i][k]="1";
                    }
                }
            }
        }

        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=="0") ans++;
                // cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
        // cout<<endl;

        return ans;
    }
};