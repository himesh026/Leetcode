// Problem: Moving Stones Until Consecutive
// URL: https://leetcode.com/problems/moving-stones-until-consecutive/

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        
        vector<int> postn={a,b,c};
        sort(postn.begin(),postn.end());
        int x=0,y=0;
        int mini=0;
        int maxi=0;
        for(int i=1;i<3;i++){

            if(postn[i]-postn[i-1]-1==0) y++; // already consecutive 2,3
            else if(postn[i]-postn[i-1]-1==1) x++; // 1 distance gap 2,4
            maxi+=postn[i]-postn[i-1]-1;
        }

        if(y==1 || x>0) mini=1;
        else if(y==2) mini=0;
        else{
            mini=2;
        }

        return {mini,maxi};
    }
};


//minimum move 0,1,2 hi ho skte ise jyada nhi hoge
// 0-> when stones are already consecutive like => 2,3,4 or 12,13,14
// 1-> possible when 2 stones are consecutive but one is not or 2 of three stones are 1 distance gap
// 2,3,5 or 4,8,9 here 2 stones are consecutive
// 5,7,9 here 1 distance gap 
// 2-> only possible when all thress stones are ditant with more than 1 distnace between them
// 2,6,9 or 23,30,35

// //maximum steps can be total diffrence between sorted stones 