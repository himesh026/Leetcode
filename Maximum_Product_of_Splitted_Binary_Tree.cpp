// Problem: Maximum Product of Splitted Binary Tree
// URL: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/?envType=daily-question&envId=2026-01-07

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
    int totalSum=0;

    void calcTotalSum(TreeNode* root){

        if(root==NULL){
            return;
        }

        totalSum+=root->val;

        calcTotalSum(root->left);
        calcTotalSum(root->right);
    }


    long long ans=0;
    int mod=1e9+7;
    long long solve(TreeNode* root){

        if(root==NULL){
            return 0;
        }
        long long leftSum=solve(root->left);
        long long rightSum=solve(root->right);
        long long subtreeSum=leftSum+rightSum+root->val;
        ans=max(ans,((totalSum-subtreeSum)*subtreeSum));
        return subtreeSum;
    }
    int maxProduct(TreeNode* root) {
        
        calcTotalSum(root);
        solve(root);

        return ans%mod;
    }
};