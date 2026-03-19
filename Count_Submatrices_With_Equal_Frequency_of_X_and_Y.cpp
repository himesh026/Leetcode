// Problem: Count Submatrices With Equal Frequency of X and Y
// URL: https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/?envType=daily-question&envId=2026-03-19

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<pair<int,int> > > hash(n,vector<pair<int,int>>(m,{0,0}));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X'){
                    hash[i][j].first+=1;
                }
                else if(grid[i][j]=='Y'){
                    hash[i][j].second+=1;
                }
            }
        }
        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){
                // cout<<hash[i][j].first<<" "<<hash[i][j].second<<endl;
                if(i-1>=0){
                    hash[i][j].first+=hash[i-1][j].first;
                    hash[i][j].second+=hash[i-1][j].second;
                }
                if(j-1>=0){
                    hash[i][j].first+=hash[i][j-1].first;
                    hash[i][j].second+=hash[i][j-1].second;                    
                }
                if(i-1>=0 && j-1>=0){
                    hash[i][j].first-=hash[i-1][j-1].first;
                    hash[i][j].second-=hash[i-1][j-1].second;                     
                }

                if(hash[i][j].first==hash[i][j].second && hash[i][j].first!=0){
                    //freq x==freq y
                    ans++;
                }
            }

            // cout<<endl;
        }

        return ans;
    }
};