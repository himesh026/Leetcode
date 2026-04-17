// Problem: Maximum Consecutive Floors Without Special Floors
// URL: https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n=special.size();
        sort(special.begin(),special.end());


        int len=max(special[0]-bottom,top-special[n-1]);

        for(int i=1;i<n;i++){
            len=max(len,special[i]-special[i-1]-1);
        }

        return len;
    }
};

// //first thought 
// ki bottom se top k sare floors ek array m store kr va lunga fir special floors ko -1 kr dunga to mera question bn gya find the maximum contonius +ve floors but 1 <= bottom <= special[i] <= top <= 10^9 to itne sare store krvane Memory limit exceed aagya 
// //2nd thought
// ki store kyu krvane jb traverse bottom se top kra to direct ek loop bottom se top pr chlata hu and specaila floors ko set m daal deta hu simple check kr lunga maximum continous floor not found in set
// but 1 <= bottom <= special[i] <= top <= 10^9 to Inte m to tle aagya
// //3rd thought 
// ki special array ko sort kr leta hu len=len=max(special[0]-bottom,top-special[n-1]); 
// and special array pr loop chalta hu len ko update kr deta hu len=max(len,special[i]-special[i-1]-1);
// ese hoga nlogn m n-> length of specail array