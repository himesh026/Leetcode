// Problem: Minimum Absolute Distance Between Mirror Pairs
// URL: https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/?envType=daily-question&envId=2026-04-17

class Solution {
public:
    int reversefxn(int n){
        string N=to_string(n);
        int i=N.size()-1;
        int revnum=0;

        while(n>0){
            int lastdigit=n%10;
            revnum+=pow(10,i)*lastdigit;
            i--;
            n=n/10;
        }

        return revnum;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> hash;

        for(int i=0;i<n;i++){
            hash[nums[i]].push_back(i);
        }

        int ans=INT_MAX;
        // for(auto it:hash){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        for(int i=0;i<n;i++){
            int x=reversefxn(nums[i]);
            //agr nums[i] ka reverse exssit hi nhi krta to continue
            if(hash.find(x)==hash.end()) continue;
            //agr exsist krta h and ek bar hi and dono equal h like nums[i]=33 , x=33 . to mtlb ye puri array m ek bar hi aaya h to pair nhi bna skte to continue;
            else if(hash[x].size()==1 && x==nums[i]) continue;
            //agr reverse exsist krte h but vo sare piche h like [12,12,10,12,3,21] ab 21 ka reverse h 12 or vo sare use phle exsit krte h and already apno ne left to right traverse krte vaqt jb 12 aaya hoga to uska reversed 21 cover ho chuka h 
            else if(hash[x].back()<=i) continue;
            else{
                
                int indx=upper_bound(hash[x].begin(),hash[x].end(),i)-hash[x].begin();
                ans=min(ans,hash[x][indx]-i);
            }
        }

        return ans==INT_MAX? -1:ans;
    }
};