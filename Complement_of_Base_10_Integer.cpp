// Problem: Complement of Base 10 Integer
// URL: https://leetcode.com/problems/complement-of-base-10-integer/?envType=daily-question&envId=2026-03-11

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int ans=0;
        int j=0;

        while(n>0){

            if(!(n&1)){
                ans+=pow(2,j);
            }
            j++;
            n=n/2;
        }

        return ans;
    }
};