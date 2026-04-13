// Problem: Swap For Longest Repeated Character Substring
// URL: https://leetcode.com/problems/swap-for-longest-repeated-character-substring/

class Solution {
public:
    int maxRepOpt1(string text) {
        int n=text.size();
        vector<vector<int> > indx(26);
        
        for(int i=0;i<n;i++){
            indx[text[i]-'a'].push_back(i);
        }
        int ans=0;          
        for(int i=0;i<26;i++){
            int cnt=1;
            int prevcnt=0;
            int mx=0;
            for(int j=1;j<indx[i].size();j++){
                if(indx[i][j]==(indx[i][j-1]+1)) cnt++;
                else{
                    prevcnt=(indx[i][j]==(indx[i][j-1]+2))? cnt:0;
                    cnt=1;
                }
                mx=max(mx,cnt+prevcnt);

            }
            //checking ki agr jitne i char h unte ka hi group bn gya h to bbeech m ek char tha ya sare contonous hi the => aaabaaa or aaaaaaab , but agr 2 char h or current i char or available h to +1 kr skte ek swap se => aaabcaa => aaaacba or aaaacab or cabaaaa or acbaaaa
            ans=max(ans,mx+((indx[i].size()==mx)?0:1));
        }

        return ans;
    }
};

// my thought process is prefix and suffix array on each chars as thier can be only 26 chars but this thinking is wrong and after reading solution i fet what is the correct approach 
// we can olny merge two same char groups if they are seprated by only one char as in problem we can do atmost one swap 
// example=> S="aaabaaa" in this a gropus are seprated by single char so we can swap this seprating char with end of last group or with start of first group => "aaaaaab" or "baaaaaa" 
// but if groups are sperated by more then one char wer cant merge them as atmost one swap is possible 
// example S="aaabcaaa" in this we can only achive aaaac... or ....baaaa 
// so we will first store each char index where they exsist if a contnous range is exsisting we will cnt++ nad if it breaks by a single char then prevcnt=cnt and start new cnt=1 , but if seprated by 2 then prevcnt=0 cnt=1, but agr jb 2 se seprate kre to bs ye check kro ki same char ki or availblity h to ek swap krk ans+=1 kr skte 


// https://leetcode.com/problems/swap-for-longest-repeated-character-substring/solutions/355922/c-2-approaches-by-votrubac-gik8