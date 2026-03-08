// Problem: Find Unique Binary String
// URL: https://leetcode.com/problems/find-unique-binary-string/submissions/1941727914/?envType=daily-question&envId=2026-03-08

class Solution {
public:
    int btoint(string str){
        int ans=0;
        int x=0;
        for(int i=str.size()-1;i>=0;i--){
            if(str[i]=='1') ans+=pow(2,x);
            x++;
        }

        return ans;
    }
    string inttobin(int num,int len){
        string str=string(len,'0');
        int i=len-1;
        while(num>0){
            if(num&1){
                str[i]='1';
            }
            num=num/2;
            i--;
        }

        return str;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        
        int binlen=nums[0].size();

        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(btoint(nums[i]));
        }

        for(int i=0;i<pow(2,binlen);i++){
            if(st.find(i)==st.end()){
                string ans=inttobin(i,binlen);
                return ans;
            }
        }

        return "";
    }
};