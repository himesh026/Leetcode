// Problem: Binary Number with Alternating Bits
// URL: https://leetcode.com/problems/binary-number-with-alternating-bits/?envType=daily-question&envId=2026-02-18

class Solution {
public:
    bool hasAlternatingBits(int n) {
        if(n%2==0){
            bool iszero=true;
            while(n>0){
                int lastbit=n%2;
                if(lastbit==0 && iszero==true){
                    iszero=false;
                }
                else if(lastbit==1 && iszero==false){
                    iszero=true;
                }
                else return false;
                n=n/2;
            }
        }
        else{
            bool iszero=false;
            while(n>0){
                int lastbit=n%2;
                if(lastbit==1 && iszero==false){
                    iszero=true;
                }
                else if(lastbit==0 && iszero==true){
                    iszero=false;
                }
                else return false;
                n=n/2;
            }
        }

        return true;
    }
};
