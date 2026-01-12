// Problem: Minimum Time Visiting All Points
// URL: https://leetcode.com/problems/minimum-time-visiting-all-points/?envType=daily-question&envId=2026-01-12

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int time=0;

        for(int i=1;i<points.size();i++){
            int dx=abs(points[i][0]-points[i-1][0]);
            int dy=abs(points[i][1]-points[i-1][1]);
            time+=max(dx,dy); 
        }


        return time;
    }
};