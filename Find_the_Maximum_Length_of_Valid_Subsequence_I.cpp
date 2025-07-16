// Problem: Find the Maximum Length of Valid Subsequence I
// URL: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/?envType=daily-question&envId=2025-07-16

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0;
        int odd=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) even++;
            else odd++;
        }
        int alt01=0; // even odd even odd ....
        bool flag1=true;
        int alt10=0; // odd even odd even ....
        bool flag2=false;

        //even odd even odd...

        for(int i=0;i<nums.size();i++){
            if(flag1 && nums[i]%2==0){
                alt01++;
                flag1=false;
            }
            else if(flag1==false && nums[i]%2!=0){
                flag1=true;
                alt01++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(flag2==false && nums[i]%2!=0){
                alt10++;
                flag2=true;
            }
            else if(flag2==true && nums[i]%2==0){
                flag2=false;
                alt10++;
            }
        }
        // cout<<even<<" "<<odd<<" "<<alt01<<" "<<alt10<<endl;
        return max(max(odd,even),max(alt01,alt10));
        
    }
};