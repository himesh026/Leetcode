// Problem: Reverse Bits
// URL: https://leetcode.com/problems/reverse-bits/?envType=daily-question&envId=2026-02-16

class Solution {
public:
    int reverseBits(int n) {
        vector<int> binaryarr(32,0);
        int i=31;
        while(n>0){
            binaryarr[i]=(n&1);
            i--;
            n=n/2;
        } 

        reverse(binaryarr.begin(),binaryarr.end());

        int ans=0;
        int j=0;
        for(int i=31;i>=0;i--){
            ans+=binaryarr[i]*pow(2,j);
            j++;
        }

        return ans;
    }
};