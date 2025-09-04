// Problem: Find Closest Person
// URL: https://leetcode.com/problems/find-closest-person/?envType=daily-question&envId=2025-09-04

class Solution {
public:
    int findClosest(int x, int y, int z) {
        
        if(abs(z-x)>abs(z-y)) return 2;
        if(abs(z-x)==abs(z-y)) return 0;
        return 1;
    }
};