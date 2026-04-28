// Problem: Minimum Operations to Make a Uni-Value Grid
// URL: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/?envType=daily-question&envId=2026-04-28

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        int m=grid.size();
        int n=grid[0].size();
        vector<int> arr;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr.push_back(grid[i][j]);

            }
        }

        sort(arr.begin(),arr.end());
        int minOprn=0;

        int median=arr[m*n/2];
        for(int i=0;i<m*n;i++){
            if(abs(median-arr[i])%x==0){
                minOprn+=abs(median-arr[i])/x;
            }
            else{
                return -1;
            }
        }


        return minOprn;


    }
};

//simple thought ki sbhi elemnets ko median k barabr krdunga, number of elemnts odd h tb median ek hi hoga but even k case m 2 median so men dono ko conside kiya or jo minimum dega use rkh lunga but this is not needed ek median se bhi kaam chal jayega kyunki jb do median h agr 1st consider kiya to 2nd pr operation hoge and 2nd conside kiya to 1st pr equal number of operation hoge so no need of checking number of elemts are even or odd.