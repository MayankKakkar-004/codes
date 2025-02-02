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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        queue<pair<TreeNode*, unsigned long long>> que;
        que.push({root, 0});
        long long maxWidth = 0;

        while (!que.empty()) {
            long long L = que.front().second;  // First index in level
            long long R = que.back().second;   // Last index in level
            maxWidth = max(maxWidth, R - L + 1);
            
            int n = que.size();
            for (int i = 0; i < n; i++) {
                auto [curr, idx] = que.front();
                que.pop();
                
                if (curr->left) {
                    que.push({curr->left, 2 * (idx - L)});  // Normalize index to prevent overflow
                }
                if (curr->right) {
                    que.push({curr->right, 2 * (idx - L) + 1});
                }
            }
        }
        return maxWidth;
    }
};