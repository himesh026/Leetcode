// Problem: Words Within Two Edits of Dictionary
// URL: https://leetcode.com/problems/words-within-two-edits-of-dictionary/?envType=daily-question&envId=2026-04-22

class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        
        int cnt=0;
        vector<string> ans;
        for(int i=0;i<q.size();i++){
            bool ismatched=false;
            for(int j=0;j<d.size();j++){
                if(q[i].size()!=d[j].size()) continue;
                int diff=0;
                for(int k=0;k<q[i].size();k++){
                    if(q[i][k]!=d[j][k]) diff++;
                    if(diff>2) break;
                }
                if(diff<=2){
                    ismatched=true;
                    ans.push_back(q[i]);
                    break;
                }
            }
        }

        return ans;
    }
};

//simply bruteforce constraint are small , hr query k word ko dictonary k hr word se match kr lenge ager diff<=2 h to mlb 2 edit m euqal ho skta 