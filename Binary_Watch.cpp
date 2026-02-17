// Problem: Binary Watch
// URL: https://leetcode.com/problems/binary-watch/?envType=daily-question&envId=2026-02-17

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        
        vector<int> hours;
        unordered_map<int,int> hoursbinaryOne;
        for(int i=0;i<12;i++){
            hours.push_back(i);
            int x= __builtin_popcount(i);
            hoursbinaryOne[i]=x;
        }
        vector<int> mins;
        unordered_map<int,int> minsbinaryOne;
        for(int i=0;i<60;i++){
            mins.push_back(i);
            int x= __builtin_popcount(i);
            minsbinaryOne[i]=x;
        }
        vector<string> ans;
        for(auto it:hoursbinaryOne){
            for(auto iit:minsbinaryOne){
                if(it.second+iit.second==turnedOn){
                    string h=to_string(it.first);
                    string m=to_string(iit.first);
                    if(iit.first<10){
                        m="0"+m;
                    }
                    string temp=h+":"+m;
                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }
};