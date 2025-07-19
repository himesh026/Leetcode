// Problem: Remove Sub-Folders from the Filesystem
// URL: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/?envType=daily-question&envId=2025-07-19

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        string prevFolder="";
        vector<string> ans;
        ans.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string currFolder=folder[i];
            string prevFolder=ans.back()+"/";
            bool flag=true; // subfolder h
            for(int j=0;j<prevFolder.size();j++){
                if(j>folder[i].size() || prevFolder[j]!=currFolder[j]){
                    flag=false; //subfolder nhi h
                    break;
                }
            }

            if(!flag){
                ans.push_back(currFolder);
            }

            

        }

        return ans;
    }
};