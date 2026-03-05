// Problem: Minimum Changes To Make Alternating Binary String
// URL: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/?envType=daily-question&envId=2026-03-05

class Solution {
public:
    int minOperations(string s) {
        string type1="";
        string type2="";
        int x=0;
        for(int i=0;i<s.size();i++){
            type1+=to_string(x);
            type2+=to_string(!x);
            x=!x;
        }

        int opt1=0;
        int opt2=0;

        for(int i=0;i<s.size();i++){
            if(s[i]!=type1[i]) opt1++;
            if(s[i]!=type2[i]) opt2++;

        }

        return min(opt1,opt2);
    }
};