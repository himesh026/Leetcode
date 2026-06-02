// Problem: Earliest Finish Time for Land and Water Rides I
// URL: https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/?envType=daily-question&envId=2026-06-02

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int ans=1e9;

        for(int i=0;i<landStartTime.size();i++){
            int ls=landStartTime[i];
            int ld=landDuration[i];
            int temp=ls+ld;
            for(int j=0;j<waterStartTime.size();j++){
                int ws=waterStartTime[j];
                int wd=waterDuration[j];
                if(ws<=temp){
                    ans=min(ans,temp+wd);
                }
                else{
                    ans=min(ans,ws+wd);
                }
            }
        }
        for(int i=0;i<waterStartTime.size();i++){
            int ws=waterStartTime[i];
            int wd=waterDuration[i];
            int temp=ws+wd;
            for(int j=0;j<landStartTime.size();j++){
                int ls=landStartTime[j];
                int ld=landDuration[j];
                if(ls<=temp){
                    ans=min(ans,temp+ld);
                }
                else{
                    ans=min(ans,ls+ld);
                }
            }
        }
        return ans;

    }
};

