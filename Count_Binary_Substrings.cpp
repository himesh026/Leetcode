// Problem: Count Binary Substrings
// URL: https://leetcode.com/problems/count-binary-substrings/?envType=daily-question&envId=2026-02-19

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        int zero=0;
        int one=0;
        int ans=0;
        int i=0;
        while(i<n){
            bool flag=false;
            zero=0;
            while(i<n && s[i]=='0'){
                i++;
                zero++;
                flag=true;
            }
            ans+=min(zero,one);
            one=0;
            while(i<n && s[i]=='1'){
                i++;
                one++;
                flag=false;
            }
            ans+=min(zero,one);
            if(flag==false) zero=0;
            else one=0;
        }

        return ans;
    }
};