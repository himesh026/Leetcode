// Problem: Unique Length-3 Palindromic Subsequences
// URL: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/?envType=daily-question&envId=2026-03-23

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        unordered_map<char,int> suffixFreq;
        unordered_map<char,int> prefixFreq;

        for(int i=0;i<s.size();i++){
            suffixFreq[s[i]]++;
        }

        unordered_set<string> validPalindromes;

        for(int i=0;i<s.size();i++){
            suffixFreq[s[i]]--;
            prefixFreq[s[i]]++;
            string temp=string('#',3);
            temp[1]=s[i]; //current elem as middle

            for(auto it:prefixFreq){
                int f1=it.second;
                char elm=it.first;
                if(s[i]==elm && f1<=1) continue;
                if(suffixFreq[elm]>=1){
                    temp[0]=elm;
                    temp[2]=elm;
                    validPalindromes.insert(temp);
                }
            }
        }

        int ans=validPalindromes.size();

        return ans;
    }
};