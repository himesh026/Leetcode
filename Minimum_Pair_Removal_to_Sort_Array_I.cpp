// Problem: Minimum Pair Removal to Sort Array I
// URL: https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/?envType=daily-question&envId=2026-01-22

class Solution {
public:
    bool isSorted(vector<int>&arr){

        for(int i=1;i<arr.size();i++){
            if(arr[i]>=arr[i-1]) continue;
            else return false;
        }

        return true;
    }
    void print(vector<int> arr){

        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" "<<", ";
        }
        cout<<endl;
    }
    int minimumPairRemoval(vector<int>& nums) {
        
        int cnt=0;
        while(1){
            if(isSorted(nums)) return cnt;
            int minadj=INT_MAX;
            int index=0;
            for(int i=1;i<nums.size();i++){
                if((nums[i]+nums[i-1])<minadj){
                    minadj=nums[i]+nums[i-1];
                    index=i-1;
                }
            }
            vector<int> temp;
            for(int i=0;i<nums.size();i++){
                if(i==index){
                    temp.push_back(minadj);
                }
                else if(i==index+1){
                    continue;
                }
                else{
                    temp.push_back(nums[i]);
                }
            }
            cnt++;
            nums=temp;
        }

        return cnt;
    }
};