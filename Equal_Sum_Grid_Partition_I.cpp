// Problem: Equal Sum Grid Partition I
// URL: https://leetcode.com/problems/equal-sum-grid-partition-i/?envType=daily-question&envId=2026-03-25

class Solution {
public:
    bool solve(vector<long long>& arr){
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            if(arr[i]==(arr[n-1]-arr[i])) return true;
        }

        return false;
    }
    void print(vector<int> arr){
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" , ";
        }
        cout<<endl;
    }
    void printgrid(vector<vector<long long>> grid){

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<grid[i][j]<<" , ";
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;
    }
    void valueAssign(vector<vector<long long>> &temp,
vector<vector<int>>& grid){

    int n=temp.size();
    int m=temp[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp[i][j]=grid[i][j];
        }
    }
}
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long long>> temp(n,vector<long long>(m));

        valueAssign(temp,grid);
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                temp[i][j]+=temp[i][j-1];
            }
        }
        vector<long long> row(m,0);

        for(int i=0;i<m;i++){
            long long sum=0;
            for(int j=0;j<n;j++){
                sum+=temp[j][i];
            }
            row[i]=sum;
        }
        // printgrid(temp);
        valueAssign(temp,grid);

        // printgrid(temp);
       
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                temp[j][i]+=temp[j-1][i];
            }
        }
        vector<long long> colm(n,0);

        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=0;j<m;j++){
                sum+=temp[i][j];
            }
            colm[i]=sum;
        }
        // printgrid(temp);
        // print(row);
        // print(colm);
        if(solve(row) || solve(colm)) return true;

        return false;
    }
};