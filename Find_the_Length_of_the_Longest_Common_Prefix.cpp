// Problem: Find the Length of the Longest Common Prefix
// URL: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/?envType=daily-question&envId=2026-05-21

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        if(arr1.size()>arr2.size()){ //speed bdhane k liye bs
            longestCommonPrefix(arr2,arr1);
        }
        unordered_set<int> prefix;

        for(int i=0;i<arr1.size();i++){
            int x=arr1[i];
            while(x>0){
                prefix.insert(x);
                x=x/10;
            }
        }


        int ans=0;

        for(int i=0;i<arr2.size();i++){
            int x=arr2[i];
            while(x>0){
                if(prefix.find(x)!=prefix.end()){
                    string str=to_string(x);
                    ans=max(ans,(int)str.size());
                }
                x=x/10;
            }
        }

        return ans;
    }
};


//kuch nhi bs ek array k sare prefix bnalo or set m store krlo , or dusri array pr traverse krk check krlo