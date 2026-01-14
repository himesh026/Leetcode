// Problem: Separate Squares I
// URL: https://leetcode.com/problems/separate-squares-i/?envType=daily-question&envId=2026-01-13

class Solution {
public:

    double areaAbove(double y0,vector<vector<int>>& squares){

        double area=0;
        for(int i=0;i<squares.size();i++){
            if(squares[i][1]>=y0){ // sqaure lie above or on the line y=y0
                area+=(double)squares[i][2]*squares[i][2]; //side^2
            }
            else if(squares[i][1]<y0 && (squares[i][1]+squares[i][2])>y0){
                //intersectiong
                area+=(double)(squares[i][1]+squares[i][2]-y0)*squares[i][2]; //(top-y0)*width
            }
        }

        return area;
    }
    double areaBelow(double y0,vector<vector<int>>& squares){

        double area=0;
        for(int i=0;i<squares.size();i++){
            if(squares[i][1]+squares[i][2]<=y0){ // sqaure lie below or on the line y=y0
                area+=(double)squares[i][2]*squares[i][2]; //side^2
            }
            else if(squares[i][1]<y0 && (squares[i][1]+squares[i][2])>y0){
                //intersectiong
                area+=(double)(y0-squares[i][1])*squares[i][2]; //(y0-below)*width
            }
        }

        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        
        int minY=INT_MAX;
        int maxY=INT_MIN;
        for(int i=0;i<squares.size();i++){
            minY=min(minY,squares[i][1]);
            maxY=max(maxY,squares[i][1]+squares[i][2]);
        }

        
        double lo = minY, hi = maxY;
        double eps = 1e-6;

        while (hi - lo > eps) {
            double mid = lo + (hi - lo) / 2;

            double above = areaAbove(mid, squares);
            double below = areaBelow(mid, squares);
            // cout<<above<<endl;
            // cout<<below<<endl;
            if (above > below) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        return lo;
    }
};