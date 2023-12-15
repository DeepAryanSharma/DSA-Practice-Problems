class Solution {
public:
    void inorderHelper(TreeNode* &root, vector<int> &ans){
        //base case
        if(root==NULL){
            return;
        }

        //left part
        inorderHelper(root->left, ans);
        //curr node
        ans.push_back(root->val);
        //right part
        inorderHelper(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderHelper(root,ans);

        return ans;
        
    }
};
