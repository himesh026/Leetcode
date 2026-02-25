// Problem: Sum of Root To Leaf Binary Numbers
// URL: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/?envType=daily-question&envId=2026-02-24

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,string &path,vector<string> &allNums){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            path+=to_string(root->val);
            allNums.push_back(path);
            path.pop_back();
            return;
        }
        //preorder
        path+=to_string(root->val);
        solve(root->left,path,allNums);
        solve(root->right,path,allNums);
        path.pop_back();

    }
    int binaryStringtoInt(string str){
        int num=0;
        int j=0;
        for(int i=str.size()-1;i>=0;i--){
            if(str[i]=='1'){
                num+=pow(2,j);
            }
            j++;
        }
        return num;
    }
    int sumRootToLeaf(TreeNode* root) {

        vector<string> allNums; // root to leaf path
        string path="";
        solve(root,path,allNums);

        int ans=0;

        for(int i=0;i<allNums.size();i++){
            ans+=binaryStringtoInt(allNums[i]);
        }

        return ans;
    }
};