// Problem: Count the Number of Special Characters II
// URL: https://leetcode.com/problems/count-the-number-of-special-characters-ii/?envType=daily-question&envId=2026-05-27

class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        vector<int> small(26,-1);
        vector<int> capital(26,-1);
        unordered_set<char> s;
        unordered_set<char> c;
        for(char ch='a';ch<='z';ch++){
            s.insert(ch);
        }
        for(char ch='A';ch<='Z';ch++){
            c.insert(ch);
        }
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(s.find(ch)!=s.end()){
                small[ch-'a']=i;
            }
            else if(c.find(ch)!=c.end() && capital[ch-'A']==-1){
                capital[ch-'A']=i;
            }
        }

        int ans=0;

        for(int i=0;i<26;i++){
            if(small[i]!=-1 && capital[i]!=-1 && small[i]<capital[i]) ans++;
        }

        return ans;

    }
};