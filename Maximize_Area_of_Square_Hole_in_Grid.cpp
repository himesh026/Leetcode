// Problem: Maximize Area of Square Hole in Grid
// URL: https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/?envType=daily-question&envId=2026-01-15

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        
        int hcont=0; // continous horizontal bar kitne h
        int vcont=0; // continous vertical bar kitne h
        sort(hBars.begin(),hBars.end()); 
        int cnt=1;
        //get maximum number of continous horizontal bar
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]-hBars[i-1]==1){
                cnt++;
            }
            else{
                hcont=max(hcont,cnt);
                cnt=1;
            }
        }
        hcont=max(hcont,cnt);

        sort(vBars.begin(),vBars.end());
        cnt=1;
        //get maximum number of continous vertical bars
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]-vBars[i-1]==1){
                cnt++;
            }
            else{
                vcont=max(vcont,cnt);
                cnt=1;
            }
        }
        vcont=max(vcont,cnt);
        //square side
        int side=min(hcont,vcont)+1;

        return side*side;
    }
};

//from observation 
//to get side=2 square we need 1 contoonous horizontal, 1 continous vertical bar
// to get side=3 square we need 2 contoonous horizontal, 2 continous vertical bar
// to get side=4 square we need 3 contoonous horizontal, 3 continous vertical bar
// to get side=n square we need (n-1) contoonous horizontal, (n-1) continous vertical bar