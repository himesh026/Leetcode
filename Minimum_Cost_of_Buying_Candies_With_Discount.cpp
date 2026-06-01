// Problem: Minimum Cost of Buying Candies With Discount
// URL: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/description/?envType=daily-question&envId=2026-06-01

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.rbegin(),cost.rend());

        int minCost=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt++;
            if(cnt==3){
                //free
                cnt=0;
                continue;
            }
            else{
                minCost+=cost[i];
            }
        }

        return minCost;
    }
};