// Problem: Convert Integer to the Sum of Two No-Zero Integers
// URL: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/?envType=daily-question&envId=2025-09-08

class Solution {
public:
    bool f(int n){
        string str=to_string(n);
        for(int i=0;i<str.size();i++){
            if(str[i]=='0')return false;
        }

        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
       
       for(int i=n-1;i>=n/2;i--){
        int a=i;
        int b=n-i;
        if(f(a) && f(b)){
            return {a,b};
        }
       }

       return {-1,-1};
    }
};