// Problem: Check if Strings Can be Made Equal With Operations II
// URL: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/?envType=daily-question&envId=2026-03-30

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string s1e="",s1o="";
        string s2e="",s2o="";

        int n=s1.size(); // both have same size

        for(int i=0;i<n;i++){
            if(i%2==0){
                s1e+=s1[i];
                s2e+=s2[i];
            }
            else{
                s1o+=s1[i];
                s2o+=s2[i];
            }
        }


        sort(s1e.begin(),s1e.end());
        sort(s1o.begin(),s1o.end());
        sort(s2e.begin(),s2e.end());
        sort(s2o.begin(),s2o.end());

        if(s1e==s2e && s1o==s2o) return true;

        return false;
    }
};