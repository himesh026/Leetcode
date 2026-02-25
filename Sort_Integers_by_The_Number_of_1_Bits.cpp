// Problem: Sort Integers by The Number of 1 Bits
// URL: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/?envType=daily-question&envId=2026-02-25

class Solution {
public:
    static bool fxn(int a,int b){

        if(__builtin_popcount(a)==__builtin_popcount(b)){
            return a<b;
        }

        return __builtin_popcount(a)<__builtin_popcount(b);
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(),arr.end(),fxn);

        return arr;
    }
};