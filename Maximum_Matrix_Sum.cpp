// Problem: Maximum Matrix Sum
// URL: https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2026-01-05

class Solution {
public:

    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        int n=matrix.size(); // n*n
        int cnt=0; //count of -ve number
        long long sum=0; // abs sum
        long long absmin=INT_MAX;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0){
                    cnt++;
                }
                sum+=abs(matrix[i][j]);
                absmin=min(absmin,(long long)abs(matrix[i][j]));
                
            }
        }
        
        if(cnt%2!=0){
            sum = sum+(-2*absmin);
        }
        return sum;
    }
};