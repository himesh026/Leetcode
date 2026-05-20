// Problem: Find the Prefix Common Array of Two Arrays
// URL: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/?envType=daily-question&envId=2026-05-20

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        vector<int> ans(n,0);

        unordered_set<int> st;

        for(int i=1;i<=n;i++){
            st.insert(i);
        }

        for(int i=n-1;i>=0;i--){
            ans[i]=st.size();
            st.erase(A[i]);
            st.erase(B[i]);

        }

        return ans;
    }
};


//simply set m dalo 1 to n elements , ans[n-1]=n hi hoga ab set m se erse krdo A[n-1] and B[n-1] jo set ka size bacha vo answer hoga ans[n-2] ka and so on