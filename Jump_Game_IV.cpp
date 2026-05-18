// Problem: Jump Game IV
// URL: https://leetcode.com/problems/jump-game-iv/?envType=daily-question&envId=2026-05-18

class Solution {
public:

    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 0;

        unordered_map<int,vector<int> > hash;

        for(int i=0;i<n;i++){
            hash[arr[i]].push_back(i);
        } 

        queue<pair<int,int> > q;
        vector<int> isVis(n,0);
        isVis[0]=1;
        q.push({0,0}); // {node,distance to reach this node}

        while(q.empty()==false){
            auto [node,dist]=q.front();
            q.pop();

            if(node==n-1) return dist;

            if(node-1>=0 && isVis[node-1]==0){
                isVis[node-1]=1;
                q.push({node-1,1+dist});
            }

            if(node+1<n && isVis[node+1]==0){
                isVis[node+1]=1;
                q.push({node+1,1+dist});
            }

            for(auto it:hash[arr[node]]){
                if(isVis[it]==0){
                    isVis[it]=1;
                    q.push({it,1+dist});
                }
            }

            hash[arr[node]].clear();
        }



        return -1;
    }
};



// Intuition

// From any index i, you can jump to three types of positions:

// i - 1
// i + 1
// Any index j where arr[j] == arr[i]
// Each jump costs exactly 1 move.

// So the problem becomes:

// Find the minimum number of moves needed to reach index n - 1 from index 0.

// This is a classic shortest path in an unweighted graph problem.

// Each index is a node.
// Each valid jump is an edge.
// Every edge has weight 1.

// Whenever all edges have equal weight, BFS is the optimal algorithm.

// Why BFS?

// BFS explores nodes level by level.

// Level 0 → indices reachable in 0 jumps
// Level 1 → indices reachable in 1 jump
// Level 2 → indices reachable in 2 jumps
// ...

// The first time BFS reaches the last index, it is guaranteed to be using the minimum number of jumps.

// Why DFS Fails

// DFS goes as deep as possible before exploring alternatives.

// It may follow a very long path first:

// 0 → 1 → 2 → 3 → 4 → 5 → ...

// while a much shorter path exists:

// 0 → 4 → 9

// DFS has no natural guarantee that the first solution found is optimal.

// Why mp[arr[node]].clear() Is Critical

// Suppose value 7 occurs at 10,000 indices.

// Without clearing, every time one of those indices is visited, you iterate over all 10,000 positions again.

// With clearing, that expensive scan happens only once.