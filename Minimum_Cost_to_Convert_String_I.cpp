// Problem: Minimum Cost to Convert String I
// URL: https://leetcode.com/problems/minimum-cost-to-convert-string-i/?envType=daily-question&envId=2026-01-29

class Solution {
public:

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        if(source==target) return 0; //dono already same h

        vector<vector<int> >  adjmatrix(26,vector<int>(26,1e9));
        // khud se khudka distance =0 
        for(int i=0;i<26;i++){
            adjmatrix[i][i]=0; 
        }
        for(int i=0;i<original.size();i++){
            int u=int(original[i])-int('a');
            int v=int(changed[i])-int('a');
            //sbse min cost lo u->v
            adjmatrix[u][v]=min(adjmatrix[u][v],cost[i]);
        }



        //floyd warshal
        for(int via=0;via<26;via++){

            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(i==j) continue;
                    adjmatrix[i][j]=min(adjmatrix[i][j],adjmatrix[i][via]+adjmatrix[via][j]);
                }
            }
        }
        long long ans=0;
        //now match
        for(int i=0;i<source.size();i++){
            int u=int(source[i])-int('a');
            int v=int(target[i])-int('a');

            if(adjmatrix[u][v]==1e9) return -1; 
            ans+=adjmatrix[u][v];
        }
        return ans;
    }
};