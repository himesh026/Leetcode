// Problem: Partitioning Into Minimum Number Of Deci-Binary Numbers
// URL: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/?envType=daily-question&envId=2026-03-01

class Solution {
public:
    int minPartitions(string n) {
        int ans=0;

        for(int i=0;i<n.size();i++){
            ans=max(ans,n[i]-'0');
        }

        return ans;
    }
};