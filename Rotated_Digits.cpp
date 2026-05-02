// Problem: Rotated Digits
// URL: https://leetcode.com/problems/rotated-digits/?envType=daily-question&envId=2026-05-02

class Solution {
public:
    int solve(int n){
        int x=n;
        if(n==0 || n==1 || n==8) return 0; // after rotation number must !=x
        if(n==2 || n==5 || n==6 || n==9) return 1;

        int rot=0;
        int k=0;
        while(n>0){
            int lastdigit=n%10;
            if(lastdigit==3 || lastdigit==4 || lastdigit==7)return 0;
            else if(lastdigit==0 || lastdigit==1 || lastdigit==8){
                rot+=lastdigit*pow(10,k);
            }
            else if(lastdigit==2){
                rot+=5*pow(10,k);
            }
            else if(lastdigit==5){
                rot+=2*pow(10,k);
            }
            else if(lastdigit==6){
                rot+=9*pow(10,k);
            }
            else if(lastdigit==9){
                rot+=6*pow(10,k);
            }
            n=n/10;
            k++;
        }
        // cout<<x<<" "<<rot<<endl;
        if(rot==x) return 0;
        return 1;
    }
    int rotatedDigits(int n) {
        
        int goodInt=0;

        for(int i=1;i<=n;i++){

            goodInt+=solve(i);
        }

        return goodInt;
    }
};


//simply do bruteforce 