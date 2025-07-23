// Problem: Maximum Score From Removing Substrings
// URL: https://leetcode.com/problems/maximum-score-from-removing-substrings/?envType=daily-question&envId=2025-07-23

class Solution {
public:
    int f(string &str,char first,char second,int val){
        stack<char> hashStack;
        int ans=0;
        for(int i=0;i<str.size();i++){
            if(str[i]==second && hashStack.empty()==false && hashStack.top()==first){
                ans+=val;
                hashStack.pop();
            }
            else hashStack.push(str[i]);
        }
        //build remaing string from stack
        string temp="";
        while(hashStack.empty()==false){
            temp+=hashStack.top();
            hashStack.pop();
        }
        str=temp;
        reverse(str.begin(),str.end());
        

        return ans;
    }
    int maximumGain(string str, int x, int y) {
        int ans=0;

        if(x>=y){
            //first remove all ab then ba
            ans+=f(str,'a','b',x); //remove ab
            ans+=f(str,'b','a',y); //remove ba
        }
        else{
            //first remove all ba than ab
            ans+=f(str,'b','a',y); //remove ba
            ans+=f(str,'a','b',x); //remove ab
        }

        return ans;
       
    }
};