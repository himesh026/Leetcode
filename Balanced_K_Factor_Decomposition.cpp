// Problem: Balanced K-Factor Decomposition
// URL: https://leetcode.com/problems/balanced-k-factor-decomposition/

class Solution {
public:
    void dfs(int i,int target,int prod,vector<int>&path,vector<int>&best,vector<int>&divs,int k){
        
        if(prod==target && path.size()==k){
            int maxPath=*max_element(path.begin(),path.end());
            int minPath=*min_element(path.begin(),path.end());
            int bestMax=INT_MAX;
            int bestMin=INT_MIN;
            if(best.size()!=0){
                bestMax=*max_element(best.begin(),best.end());
                bestMin=*min_element(best.begin(),best.end());
            }
            if(best.size()==0 || (maxPath-minPath)<(bestMax-bestMin)){
                best=path;
            }
            return ;
        }
        if(i>=divs.size() || path.size()>k){
            return ;
        }
        if(path.size()<k && (long long)prod*divs[i]<=target){
            path.push_back(divs[i]);
            dfs(i,target,(long long)prod*divs[i],path,best,divs,k);
            path.pop_back();
        }

        dfs(i+1,target,prod,path,best,divs,k);

    }
    vector<int> minDifference(int n, int k) {

        
       vector<int> divs;
       for(int i=1;i<=sqrt(n);i++){

        if(n%i==0){
            if(i==(n/i)){
                divs.push_back(i);
            }
            else{
                divs.push_back(i);
                divs.push_back(n/i);
            }
        }
       }

       sort(divs.begin(),divs.end());
       vector<int> best;
       vector<int> path;
       dfs(0,n,1,path,best,divs,k);

       return best;
       
    }
};