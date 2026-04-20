// Problem: Two Furthest Houses With Different Colors
// URL: https://leetcode.com/problems/two-furthest-houses-with-different-colors/?envType=daily-question&envId=2026-04-20

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        int n=colors.size();
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(colors[i]!=colors[j]) ans=max(ans,j-i);
            }
        }

        return ans;
    }
};


//simly bruteforce 