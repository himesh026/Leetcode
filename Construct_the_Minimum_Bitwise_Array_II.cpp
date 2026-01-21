// Problem: Construct the Minimum Bitwise Array II
// URL: https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/?envType=daily-question&envId=2026-01-21

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        //nums contains only prime number
        vector<int> ans;

        for(int i=0;i<nums.size();i++){

            if(nums[i]==2){
                ans.push_back(-1);
                continue;
            }
            int cnt=0; //consecutive ones from LSB
            int temp=nums[i];
            while(temp&1){
                cnt++;
                temp=temp/2;//shift right to check next bit
            }
            ans.push_back(nums[i] ^ (1<<(cnt-1)));

        }

        return ans;
    }
};


// in binary repsentation when we flip the immediate right 1 of first zero occur from LSB , that is our ans[i] for given nums[i]

//for every even number LSB is 0 and its imediate right is nothing that why we add -1 to answer 