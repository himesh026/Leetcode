// Problem: Minimum Number of Flips to Make the Binary String Alternating
// URL: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/

class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        s+=s;
        string p1="";
        string p2="";

        for(int i=0;i<2*n;i++){

            if(i%2==0){
                p1+='1';
                p2+='0';
            }
            else{
                p1+='0';
                p2+='1';
            }
        }

        int ans=INT_MAX;
        int diff1=0;
        int diff2=0;
        int left=0;

        for(int r=0;r<2*n;r++){

            if(p1[r]!=s[r]) diff1++;
            if(p2[r]!=s[r]) diff2++;

            //window shrink
            if(r-left+1>n){
                if(p1[left]!=s[left]) diff1--;
                if(p2[left]!=s[left]) diff2--;
                left++;
            }

            if(r-left+1==n){
                ans=min(ans,min(diff1,diff2));
            }
        }

        return ans;
    }
};