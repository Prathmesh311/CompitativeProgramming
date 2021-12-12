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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        int maxLevel = -1;
        
        rightSideViewTraversal(root, rightView, 0, maxLevel);
        return rightView;
    }
    
    void rightSideViewTraversal(TreeNode* root, vector<int>& rightView, int position, int& maxLevel){
        //Base Case
        if(root == NULL){
            return;
        }
        
        //Recursive Case
        if(position > maxLevel){
            rightView.push_back(root->val);
            maxLevel = position;
        }
        
        rightSideViewTraversal(root->right, rightView, position+1, maxLevel);
        rightSideViewTraversal(root->left, rightView, position+1, maxLevel);
    }
};
