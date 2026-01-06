// Problem: Maximum Level Sum of a Binary Tree
// URL: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/?envType=daily-question&envId=2026-01-06

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

    int maxLevelSum(TreeNode* root) {
        
        

        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        int maximumLevelSum=INT_MIN;
        int ans=0;
        while(q.empty()==false){
            int currSize=q.size();
            int currlevelsum=0;

            for(int i=0;i<currSize;i++){
                TreeNode* frontNode=q.front();
                q.pop();
                currlevelsum+=frontNode->val;

                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }

            if(currlevelsum>maximumLevelSum){
                maximumLevelSum=currlevelsum;
                ans=level;
            }
            level++;
        }

        return ans;
    }
};