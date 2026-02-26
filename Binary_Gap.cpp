// Problem: Binary Gap
// URL: https://leetcode.com/problems/binary-gap/?envType=daily-question&envId=2026-02-22

class Solution {
public:
    int binaryGap(int n) {
        vector<int> postn;
        int i=0;
        int ans=0;
        while(n>0){
            if(n&1){
                postn.push_back(i);
            }
            i++;
            n=n/2;
        }

        for(int i=1;i<postn.size();i++){
            ans=max(ans,postn[i]-postn[i-1]);
        }

        return ans;
    }
};