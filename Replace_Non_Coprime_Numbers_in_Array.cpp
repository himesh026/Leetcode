// Problem: Replace Non-Coprime Numbers in Array
// URL: https://leetcode.com/problems/replace-non-coprime-numbers-in-array/?envType=daily-question&envId=2025-09-16

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st; // use vector as stack
        for (int x : nums) {
            while (!st.empty() && gcd(st.back(), x) > 1) {
                x = lcm(st.back(), x);  // merge with top
                st.pop_back();
            }
            st.push_back(x);
        }
        return st;
    }
};