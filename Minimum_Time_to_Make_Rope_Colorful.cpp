// Problem: Minimum Time to Make Rope Colorful
// URL: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/?envType=daily-question&envId=2025-11-03

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        for(int i=0;i<colors.size();i++){
            int j=i+1;
            bool flag=false;
            while(colors[i]==colors[j]){
                j++;
                flag=true;
            }
            if(flag){
                int totalTime=0;
                int maxTime=0;
                for(int k=i;k<j;k++){
                    totalTime+=neededTime[k];
                    maxTime=max(maxTime,neededTime[k]);
                }
                
                ans+=totalTime-maxTime;
                i=j-1;
            }
        }

        return ans;
    }
};