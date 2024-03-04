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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            //first node is o be inserted 
            root=new TreeNode(val);
            return root;
        }
        if(root->val > val){
            //insert in left
            root->left=insertIntoBST(root->left, val);
            return root;
        }
        else{
            //insert in right
            root->right = insertIntoBST(root->right, val);
            return root;
        }
        
    }
};
