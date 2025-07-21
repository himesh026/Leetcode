// Problem: Delete Characters to Make Fancy String
// URL: https://leetcode.com/problems/delete-characters-to-make-fancy-string/?envType=daily-question&envId=2025-07-21

class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        int i=0;
        string ans="";
        while(i<n){
            int j=i+1;
            while(s[j]==s[i]){
                j++;
            }
            if(j-i==1){
                ans+=s[i];
                i++;
            }
            else{
                ans+=s[i];
                ans+=s[i];
                i=j;
            }
        }

        return ans;
    }
};