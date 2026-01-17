// Problem: Find the Largest Area of Square Inside Two Rectangles
// URL: https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/?envType=daily-question&envId=2026-01-17

class Solution {
public:
    long long solve(pair<pair<int, int>, pair<int, int>>& a,
                    pair<pair<int, int>, pair<int, int>>& b) {
        //first rectange
        //bottomleft
        int x1 = a.first.first;
        int y1 = a.first.second;
        //topright
        int x2 = a.second.first;
        int y2 = a.second.second;

        //second rectangle
        // bottomleft
        int x3 = b.first.first;
        int y3 = b.first.second;
        //topright
        int x4 = b.second.first;
        int y4 = b.second.second;

        int width = max(0, min(x2, x4) - max(x1, x3));
        int height = max(0, min(y2, y4) - max(y1, y3));

        int side = min(width, height);
        return 1LL * side * side;
    }

    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            pair<int, int> a = {bottomLeft[i][0], bottomLeft[i][1]};
            pair<int, int> b = {topRight[i][0], topRight[i][1]};
            for (int j = i + 1; j < n; j++) {
                pair<int, int> c = {bottomLeft[j][0], bottomLeft[j][1]};
                pair<int, int> d = {topRight[j][0], topRight[j][1]};
                pair<pair<int, int>, pair<int, int>> x = {a, b};
                pair<pair<int, int>, pair<int, int>> y = {c, d};

                ans = max(ans, solve(x, y));
            }
        }
        return ans;
    }
};