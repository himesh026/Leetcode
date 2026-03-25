// Problem: Number of Steps to Reduce a Number in Binary Representation to One
// URL: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/?envType=daily-question&envId=2026-03-23

class Solution {
public:
    int numSteps(string s) {
        
        int steps=0;

        while(s.size()!=1){
            int n=s.size();
            if(s[n-1]=='0'){
                s.pop_back();
            }
            else{
                bool flag=false;
                for(int i=n-1;i>=0;i--){
                    if(s[i]=='0'){
                        s[i]='1';
                        flag=true;
                        break;
                    }
                    else{
                        s[i]='0';
                    }
                }
                if(flag==false){
                    s="1"+s;
                }
            }
            steps++;
        }
        if(s[0]=='0') steps++;
        return steps;
    }
};