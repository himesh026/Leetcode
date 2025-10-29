// Problem: Smallest Number With All Set Bits
// URL: https://leetcode.com/problems/smallest-number-with-all-set-bits/description/?envType=daily-question&envId=2025-10-29

class Solution {
public:
    int smallestNumber(int n) {
        int p=log(n)/log(2);
        return pow(2,p+1)-1;
    }
};