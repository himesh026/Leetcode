// Problem: Minimum Cost Path with Edge Reversals
// URL: https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/?envType=daily-question&envId=2026-01-27

class Solution {
public:
    map<int,list<pair<int,int> > > adjList;

    int dijkstra(int node,int n){
        if(node==n-1){
            return 0;
        }
        vector<int> dist(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > > minHeap; // {currDist,node}
        dist[node]=0;
        minHeap.push({0,node});

        while(minHeap.empty()==false){
            auto [currDist,topNode]=minHeap.top();
            minHeap.pop();

            if(currDist<dist[topNode]) continue; 

            for(auto it:adjList[topNode]){
                int edgeW=it.second;
                int v=it.first;
                if(currDist+edgeW<dist[v]){
                    dist[v]=currDist+edgeW;
                    minHeap.push({dist[v],v});
                }
            }
        }

        return dist[n-1]==1e9? -1:dist[n-1];
    }
    int minCost(int n, vector<vector<int>>& edges) {


        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];

            adjList[u].push_back({v,w});
            adjList[v].push_back({u,2*w});

        }

        return dijkstra(0,n);
    }
};

// adjList m normal or rev dono daldo , to ab ye ek type se undirected graph hi bn gya but alg cost , ab dijkstra lga dege normal vo apne aap best path chun lega