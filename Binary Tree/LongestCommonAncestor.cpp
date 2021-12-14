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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //Base Case
        if(root == NULL){
            return NULL;
        }
        
        //Recursive Case
        //if node found return
        if(root == p || root == q){
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        //If nodes found in left and right subtree return currrent root (it's LCA)
        if(left != NULL && right != NULL){
            return root;
        }
        
        //If node found in only left or right subtree return it;
        if(left != NULL){
            return left;
        }
        return right;
        
        
    }
};
