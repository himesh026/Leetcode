// Problem: Maximize Happiness of Selected Children
// URL: https://leetcode.com/problems/maximize-happiness-of-selected-children/?envType=daily-question&envId=2026-03-30

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        int n=happiness.size();
        long long ans=0;
        int cnt=0;
        sort(happiness.begin(),happiness.end());

        int i=n-1;
        while(i>=0 && k>0){
            if(cnt>happiness[i]) break;
            ans+=happiness[i]-cnt;
            cnt++;
            i--;
            k--;
        }

        return ans;
    }
};