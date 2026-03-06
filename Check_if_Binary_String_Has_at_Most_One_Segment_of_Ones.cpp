// Problem: Check if Binary String Has at Most One Segment of Ones
// URL: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/?envType=daily-question&envId=2026-03-06

class Solution {
public:
    bool checkOnesSegment(string s) {
        
        int firstOne=-1;
        int lastOne=-1;

        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                firstOne=i;
                break;
            }
        }
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                lastOne=i;
                break;
            }
        }
        if(firstOne==-1 && lastOne==-1) return false;

        for(int i=firstOne;i<=lastOne;i++){
            if(s[i]=='0') return false;
        }

        return true;
    }
};