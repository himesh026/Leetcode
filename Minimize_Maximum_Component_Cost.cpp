// Problem: Minimize Maximum Component Cost
// URL: https://leetcode.com/problems/minimize-maximum-component-cost/

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        //prims algo (minimum spanning tree)
        map<int,vector<pair<int,int>>> adjList;

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        vector<int> isVis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        
        pq.push({0,0}); //{weight,node}
        vector<int> mstWeights;

        while(pq.empty()==false){
            auto [weight,node]=pq.top();
            pq.pop();
            
            if(isVis[node]==1) continue;
            isVis[node]=true;
            mstWeights.push_back(weight);
 

            for(auto it:adjList[node]){
                int neighbour=it.first;
                int edgWeight=it.second;
                if(isVis[neighbour]!=1){
                    pq.push({edgWeight,neighbour});
                }
            }
        }
        if(n-1-(k-1)<0) return 0; // sbhi alg alg hogye 
        sort(mstWeights.begin(),mstWeights.end());
        return mstWeights[n-1-(k-1)];

        
    }
};