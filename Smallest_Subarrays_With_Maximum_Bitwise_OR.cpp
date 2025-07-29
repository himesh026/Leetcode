// Problem: Smallest Subarrays With Maximum Bitwise OR
// URL: https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/?envType=daily-question&envId=2025-07-29

class Solution {
public:
    int removingElem(int x,map<int,int>&freq){
        int j=0;
        while(x>0){
            if(x&1){
                freq[j]--;
            }
            x=x/2;
            j++;
        }

        int newOR=0;
        for(auto it:freq){
            if(it.second!=0){
                newOR+=pow(2,it.first);
            }
        }
        return newOR;
    }
    void addingElem(int x,map<int,int>&freq){
        int j=0;
        while(x>0){
            if(x&1){
                freq[j]++;
            }
            x=x/2;
            j++;
        }
        return;
    }
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        // if(n==1 && nums[0]==0) return {1};
        int maxiOR=0;
        map<int,int> maxORhash;
        for(int i=0;i<n;i++){
            maxiOR|=nums[i];
            addingElem(nums[i],maxORhash);
        }
        map<int,int> freq;

        vector<int> ans(n,0);
        int left=0,right=0;
        int currOR=0;
        for(;left<n;left++){

            if(left>0){
                currOR=removingElem(nums[left-1],freq);
                maxiOR=removingElem(nums[left-1],maxORhash);
            }
            if(currOR==maxiOR && currOR==0){
                ans[left]=1;
                continue;
            }
            while(right<n && currOR!=maxiOR){
                currOR|=nums[right];
                addingElem(nums[right],freq);
                right++;
            }

            ans[left]=right-left;
        }
        return ans;
    }
};


// puri array ka or nikal lenge ab 0th index k liye yhi maximum or h , to ab window expand krenge jb tk apna curror maxior k brabar na hi , hashmap ka use kre taki ye pta chle ki us bit ko kitno ne set kiya 