// Problem: Longest Balanced Substring I
// URL: https://leetcode.com/problems/longest-balanced-substring-i/?envType=daily-question&envId=2026-02-12

class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> freq;
            for(int j=i;j<n;j++){
                freq[s[j]]++;
                int x=freq[s[j]];
                bool flag=true;
                for(auto it:freq){
                    if(it.second==x){
                        continue;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    ans=max(ans,j-i+1);
                }
            }
        }

        return ans;
    }
};