// Problem: Path Existence Queries in a Graph I
// URL: https://leetcode.com/problems/path-existence-queries-in-a-graph-i/

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<int> maxi(n,0); // each node u can maximum node v
        maxi[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]-nums[i]<=maxDiff){
                maxi[i]=maxi[i+1];
            }
            else{
                maxi[i]=i;
            }
        }

        vector<bool> ans;

        for(int i=0;i<queries.size();i++){
            int mv=maxi[min(queries[i][0],queries[i][1])]; // maximum node where current querry minimum node can rreach
            int currentQmax=max(queries[i][0],queries[i][1]); // maximum node in current query
            // if this current query maximum node is less then maximum node where current minimum node can reach then these are in a single component 
            if(currentQmax<=mv){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }

        return ans;
        
    }
};

// you just have to find the maximum v you can reach from u 

// nums is sorted