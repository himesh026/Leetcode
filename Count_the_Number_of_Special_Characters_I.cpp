// Problem: Count the Number of Special Characters I
// URL: https://leetcode.com/problems/count-the-number-of-special-characters-i/?envType=daily-question&envId=2026-05-26

class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        vector<int> small(26,0);
        vector<int> capital(26,0);
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
                small[ch-'a']++;
            }
            else if(c.find(ch)!=c.end()){
                capital[ch-'A']++;
            }
        }

        int ans=0;

        for(int i=0;i<26;i++){
            if(small[i]!=0 && capital[i]!=0) ans++;
        }

        return ans;
    }
};