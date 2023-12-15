class Solution {
public:
    void postorderHelper(TreeNode* root, vector<int> &ans){
        //base case
        if(root==NULL){
            return;
        }

        //left part
        postorderHelper(root->left, ans);
        //right part
        postorderHelper(root->right, ans);
        //curr node
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorderHelper(root, ans);

        return ans;
        
    }
};
