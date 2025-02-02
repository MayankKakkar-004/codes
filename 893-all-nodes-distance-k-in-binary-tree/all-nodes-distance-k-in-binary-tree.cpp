/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void fun(TreeNode* root, int k, vector<int>& ans) {
        if (!root || k < 0) return;
        if (k == 0) {
            ans.push_back(root->val);
            return;
        }
        fun(root->left, k - 1, ans);
        fun(root->right, k - 1, ans);
    }

    int solve(TreeNode* root,TreeNode* target,int k,vector<int>&ans){
        if(!root)return -1;
        if(root==target){
            fun(root,k,ans);
            return 0;
        }
        int ld=solve(root->left,target,k,ans);
        if (ld != -1) {
            if (ld + 1 == k) {
                ans.push_back(root->val);
            } else {
                fun(root->right, k - ld - 2, ans);
            }
            return ld + 1;
        }
        int rd = solve(root->right, target, k, ans);
        if (rd != -1) {
            if (rd + 1 == k) {
                ans.push_back(root->val);
            } else {
                fun(root->left, k - rd - 2, ans);
            }
            return rd + 1;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        solve(root,target,k,ans);
        return ans;
    }
};