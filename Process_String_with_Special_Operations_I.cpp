// Problem: Process String with Special Operations I
// URL: https://leetcode.com/problems/process-string-with-special-operations-i/?envType=daily-question&envId=2026-06-16

class Solution {
public:
    string processStr(string s) {
        
        string result="";

        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                if(result.size()>0){
                    result.pop_back();
                }
            }
            else if(s[i]=='#'){
                result+=result;
            }
            else if(s[i]=='%'){
                reverse(result.begin(),result.end());
            }
            else{
                result+=s[i];
            }
        }

        return result;
    }
};