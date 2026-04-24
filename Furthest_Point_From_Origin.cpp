// Problem: Furthest Point From Origin
// URL: https://leetcode.com/problems/furthest-point-from-origin/?envType=daily-question&envId=2026-04-24

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int L=0,R=0;
        int dash=0;

        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L') L++;
            else if(moves[i]=='R') R++;
            else dash++;
        }

        return max(L+dash-R,R+dash-L);
    }
};