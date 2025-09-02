// Problem: Find the Number of Distinct Colors Among the Balls
// URL: https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int,int> colors; 

        unordered_map<int,int> hash; // {ball,color}

        for(int i=0;i<queries.size();i++){
            int currColor=queries[i][1];
            int currBall=queries[i][0];
            
            if(hash.find(currBall)!=hash.end()){
                //ball is already colored
                int prevColor=hash[currBall];
                colors[prevColor]--;
                if(colors[prevColor]==0) colors.erase(prevColor);
            }
            hash[currBall]=currColor;
            colors[currColor]++;
            ans.push_back(colors.size());
        } 

        return ans;
    }
};