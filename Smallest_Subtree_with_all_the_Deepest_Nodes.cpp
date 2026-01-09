// Problem: Smallest Subtree with all the Deepest Nodes
// URL: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/?envType=daily-question&envId=2026-01-09

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
    void findLeafs(TreeNode* root,int cnt,vector<pair<int,TreeNode*>> &leafNodes){

        if(root==NULL) return;

        if(root->left==NULL && root->right==NULL){
            leafNodes.push_back({cnt,root});
            return;
        }
        findLeafs(root->left,cnt+1,leafNodes);
        findLeafs(root->right,cnt+1,leafNodes);
    }
    TreeNode* findLCA(TreeNode* root,TreeNode* n1,TreeNode* n2){

        if(root==NULL){
            return NULL;
        }

        if(root==n1 || root==n2) return root;

        TreeNode* leftans=findLCA(root->left,n1,n2);
        TreeNode* rightans=findLCA(root->right,n1,n2);

        if(leftans && rightans) return root;

        return leftans==NULL? rightans:leftans;
    }
    void levelcalcn(TreeNode* root,unordered_map<TreeNode*,int> &level) {
        

        queue<TreeNode*> q;
        q.push(root);
        int currlevel=0;
        while(q.empty()==false){
            int currQsize=q.size();
            for(int i=0;i<currQsize;i++){
                TreeNode* frontNode=q.front();
                q.pop();
                level[frontNode]=currlevel;

                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
            currlevel++;
        }

    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return root;
        //calculate all leafnodes
        vector<pair<int,TreeNode*>> leafNodes;
        findLeafs(root,0,leafNodes); // find all leanodes with their distance from root

        sort(leafNodes.rbegin(),leafNodes.rend()); // decrease order
        int cnt=1; // cnt of deepest leaf nodes
        vector<TreeNode*> deepestLeafs;
        deepestLeafs.push_back(leafNodes[0].second);
        for(int i=1;i<leafNodes.size();i++){
            if(leafNodes[i].first==leafNodes[i-1].first){
                deepestLeafs.push_back(leafNodes[i].second);
            }
            else break;
        }

        if(deepestLeafs.size()==1){ // if single deepest leaf node return it
            return deepestLeafs[0];
        }

        //if more than one deep leaf roots found then we have to find entire subtree 
        TreeNode* lca=NULL;
        int currLevel=1e9;
        unordered_map<TreeNode*,int> level; // store all nodes according to thir level
        levelcalcn(root,level);

        for(int i=0;i<deepestLeafs.size();i++){
            for(int j=i+1;j<deepestLeafs.size();j++){
                TreeNode* temp=findLCA(root,deepestLeafs[i],deepestLeafs[j]);
                //if level of temp is less then currlevel then it can be our answer lca as uppermost lca is our answer to reprsent enitre subtree
                if(level[temp]<currLevel){
                    lca=temp;
                    currLevel=level[temp];
                }
                if(lca==root) return root;
            }
        }

        return lca;
    }
};