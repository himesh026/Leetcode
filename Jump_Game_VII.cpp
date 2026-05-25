// Problem: Jump Game VII
// URL: https://leetcode.com/problems/jump-game-vii/?envType=daily-question&envId=2026-05-25

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        
        int n=s.size();
        if(s[n-1]=='1') return false;
        vector<int> isVis(n,0);
        queue<int> q;
        q.push(0);
        isVis[0]=1;
        int rightMost=0; //maximum kha tk cover krliiiya already
        while(q.empty()==false){
            int currIndex=q.front();
            q.pop();

            if(currIndex==n-1) return true;

            int start=max(currIndex+minJump,rightMost);
            int end=min(currIndex+maxJump,n-1);

            for(int i=start;i<=end;i++){
                if(s[i]=='0' && isVis[i]==0){
                    q.push(i);
                    isVis[i]=1;
                }
            }

            rightMost=end+1;
        }

        return false;
    }
};

// agr last index pr "1" h to kbhi possible hi nhi h, 
//sbse phle 0th index dalo or vha se sare j start se leke end tk travel krdo jo jo s[j]==0 h and isVis[j]==false h , but apne vapis visited check na krde isliye ek rightmost ki kha tk already cover kr chiuke h 