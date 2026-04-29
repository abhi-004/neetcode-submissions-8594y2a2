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
    int countGood(TreeNode* node, int maxCount){
        if (node == nullptr) { return 0; }

        int count = (node->val >= maxCount) ? 1 : 0;
        int newMax = max(node->val, maxCount);

        count += countGood(node->left, newMax);
        count += countGood(node->right, newMax);

        return count;

    }
    int goodNodes(TreeNode* root) {
        return countGood(root, INT_MIN);
    }
};
