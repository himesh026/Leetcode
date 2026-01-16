// Problem: Maximum Square Area by Removing Fences From a Field
// URL: https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/?envType=daily-question&envId=2026-01-16

class Solution {
public:
    int calcSide(vector<int> &arr1,vector<int> &arr2){
        //find  equal element in both descending sorted array from start
        sort(arr1.rbegin(),arr1.rend());
        sort(arr2.rbegin(),arr2.rend());

        int i=0;
        int j=0;

        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]==arr2[j]){
                return arr1[i];
            }
            else if(arr1[i]>arr2[j]){
                i++;
            }
            else{
                j++;
            }
        }

        return -1;
    }
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        //we will find diff in both h and v , then maximum same diff in h and v will create a square 
        hFences.insert(hFences.begin(), 1); 
        hFences.push_back(m);
        sort(hFences.begin(),hFences.end()); 
        vector<int> hdiff;
        for(int i=0;i<hFences.size();i++){

            for(int j=i+1;j<hFences.size();j++){
                hdiff.push_back(hFences[j]-hFences[i]);
            }
        }

        vFences.insert(vFences.begin(), 1); 
        vFences.push_back(n);

        sort(vFences.begin(),vFences.end());
        vector<int> vdiff;
        for(int i=0;i<vFences.size();i++){

            for(int j=i+1;j<vFences.size();j++){
                vdiff.push_back(vFences[j]-vFences[i]);
            }
        }

        //square side
        int side=calcSide(hdiff,vdiff);
        if(side<0) return -1;
        int mod=1e9+7;
        return ((long long)side*side)%mod; 
    }
};

//this is diffrent from 2943. Maximize Area of Square Hole in Grid bcz in 2943 problem fences are continous here they can be descrete