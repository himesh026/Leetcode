// Problem: Minimize Hamming Distance After Swap Operations
// URL: https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/?envType=daily-question&envId=2026-04-21

class Solution {
public:
    void dfs(int u,vector<int> &indx,vector<int> &isVis,map<int,vector<int>> &adjList){

        isVis[u]=1;
        indx.push_back(u);

        for(auto it:adjList[u]){
            if(isVis[it]==0){
                dfs(it,indx,isVis,adjList);
            }
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        
        map<int,vector<int>> adjList; // create a graph of indexes

        for(int i=0;i<allowedSwaps.size();i++){
            int u=allowedSwaps[i][0];
            int v=allowedSwaps[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        //now for each connected component
        int n=source.size();
        vector<int> isVis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> indx; // to collect which index are exsist in a component
            if(isVis[i]==0){
                dfs(i,indx,isVis,adjList);
                unordered_map<int,int> hash;
                
                for(int j=0;j<indx.size();j++){
                    hash[source[indx[j]]]++;
                    hash[target[indx[j]]]--;
                }
                int cnt=0;
                for(auto it:hash){
                    if(it.second>=0) cnt+=it.second;
                }
                ans+=cnt;
                
            }
        }

        return ans;
    }
};

//problem simple h , source array ko target array jesa bnanana h using allowedswaps then check krna h kitni postion pr diffrent h=hamming distance
// first i thought ki m graph bna leta hu allwedswaps se taki mujhe pta lge konse index se m konse index tk ja skta hu , fir mne sbhi values k inde store krvaye h try kiya ki k m ith index se jth index ja skta ki nhi but ye approach galat h kyunki duplicate hos kste array m vo handle nhi hore 

//correct appraoch 
// graph bnana shi decesion tha but ek connected component m jo bhi index h unpr source and target values kji freequency msimatch dekh le to pta chl jayega ki kitni jagh match kr skte kinti nhi 
// fir bs sbhi connected components pr traverse kiya jo bhi unvisited node h vha se dfs or dekha ki is component m kon kon se index aa skte fir un sbhi index pr source and target ki frequncy missmatch nikala or usko answer m add kiya