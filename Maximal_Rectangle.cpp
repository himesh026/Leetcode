// Problem: Maximal Rectangle
// URL: https://leetcode.com/problems/maximal-rectangle/?envType=daily-question&envId=2026-01-11

class Solution {
public:
    int solve(vector<int> &arr){
        int n=arr.size();
        //nse
        stack<int> nseIndex; // store nse index
        vector<int> nse(n); // store coresponding nse index
        for(int i=n-1;i>=0;i--){

            while(!nseIndex.empty() && arr[nseIndex.top()]>=arr[i]){
                nseIndex.pop();
            }
            if(nseIndex.empty()){
                nse[i]=n;
            }
            else nse[i]=nseIndex.top();
            nseIndex.push(i);
        }

        //pse
        stack<int> pseIndex;
        vector<int> pse(n);

        for(int i=0;i<n;i++){
            while(!pseIndex.empty() && arr[pseIndex.top()]>=arr[i]){
                pseIndex.pop();
            }

            if(pseIndex.empty()){
                pse[i]=-1;
            }
            else pse[i]=pseIndex.top();
            pseIndex.push(i);
        }

        int maxArea=0;

        for(int i=0;i<n;i++){
            maxArea=max(maxArea,(nse[i]-pse[i]-1)*arr[i]);
        }

        return maxArea;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int> > grid(n,vector<int>(m,0));
        //first create histogram bar rows
        for(int colm=0;colm<m;colm++){
            int sum=0;
            for(int row=0;row<n;row++){
                if(matrix[row][colm]=='0'){
                    sum=0;
                    continue;
                }
                else sum+=1;
                grid[row][colm]=sum;

            }
        }

        // now we will pass each row of grid as we do in largest rectangle area in histogram , first we calculate nse,pse => area=height*(nse-pse-1)
        //nse-> next smaller element
        //pse-> previous smaller element

        int maxArea=0;
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,solve(grid[i]));
        }

        return maxArea;
    }
};


// 1 0 1 0 0 
// 1 0 1 1 1     
// 1 1 1 1 1 
// 1 0 0 1 0 

// change to 

// 1 0 1 0 0 
// 2 0 2 1 1 
// 3 1 3 2 2 
// 4 0 0 3 0 