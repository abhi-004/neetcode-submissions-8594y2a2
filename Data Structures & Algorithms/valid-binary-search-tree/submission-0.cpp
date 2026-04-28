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
    bool validBST(TreeNode* node, TreeNode* low, TreeNode* high){
        if (node == nullptr) { return true; }

        if (low != nullptr && node->val <= low->val) {return false;}
        if (high != nullptr && node->val >= high->val) {return false;}

        return validBST(node->left, low, node) && validBST(node->right, node, high);
    }
    bool isValidBST(TreeNode* root) {
        return validBST(root, nullptr, nullptr);
        
    }
};
