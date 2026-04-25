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
    bool balanced = true;
    int checkHeight(TreeNode* node){
        if(!node) { return 0; }
        return 1 + max(checkHeight(node->left), checkHeight(node->right));
    }
    bool checkBalanced(TreeNode* node){
        if(!node) { return true; }

        int left = checkHeight(node->left);
        int right = checkHeight(node->right);
        if ((abs(left-right) <= 1) &&
        checkBalanced(node->left) && 
        checkBalanced(node->right)){
            balanced = balanced && true;
        }
        else{
            balanced = balanced && false;
        }
        return balanced;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) { return true; }
        return checkBalanced(root);
    }
};
