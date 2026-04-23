// Problem: Sum of Distances
// URL: https://leetcode.com/problems/sum-of-distances/?envType=daily-question&envId=2026-04-23

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        
        unordered_map<int,vector<int> > hash1; //index
        unordered_map<int,vector<long long> > hash2; //prefix sum of index
        int n=nums.size();
        for(int i=0;i<n;i++){
            hash1[nums[i]].push_back(i);
            if(hash2[nums[i]].size()==0){
                hash2[nums[i]].push_back(i);
            }
            else{
                hash2[nums[i]].push_back(hash2[nums[i]].back()+i);
            }
        }

        vector<long long > ans(n,0);

        for(int i=0;i<n;i++){
            int elem=nums[i];
            int totalfreq=hash1[elem].size();
            int j=lower_bound(hash1[elem].begin(),hash1[elem].end(),i)-hash1[elem].begin();
            int x=j+1; // mod will open as it is
            int y=totalfreq-x; // mod will open with -
            int h2s=hash2[elem].size();
            ans[i]= (long long)x*i-hash2[elem][j] - ((long long)y*i-(hash2[elem][h2s-1]-hash2[elem][j]));
        }

        return ans;
    }
};

// //problem is simple 
// ans[i]=sum of all |i-j| where elment nums[i]==nums[j]; i!=j
// we can neglect i!=j as if we consider it dont contribute in answer because |i-j|=0 when i=j
// //first thouht =>TLE
// i thought ki ek map bna map<int,vector<int>> lenge jisme hr element kis kis index m ayya h store krva lenge and then array pr traverse krenge and fir us elemt ki index aaray pr traverse krenge sum+=abs(i-j);
// where i is nums traverse pointer and j is current elemnt hash vector pointer and ans[i]=sum but this approach will give tle because i worst case it is n^2
// //2nd thought => use mod property
// so in this problem till a particular point mod open as it is but then it will open with - sign, so we need to find till when mod is open with as it is then - sigh , so i kept 2 map hash1 sotre elemt and where it exist indexes and hash2 store elemt and its index prefix sum , 
// now we trraverse the nums array and we will find where the current i exsist in the hash1[currentelem] array so eg j till (j+1) number of elmets mod will open as it is and hash1[currentelem].size()-(j+1) for this much elemts mod will open with - sign then simple math 