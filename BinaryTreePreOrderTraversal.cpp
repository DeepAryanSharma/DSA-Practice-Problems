class Solution {
public:
    void preorderHelper(TreeNode* root, vector<int> &ans){
        //base case
        if(root==NULL){
            return;
        }

        //curr node
        ans.push_back(root->val);
        //left part
        preorderHelper(root->left, ans);
        //right part
        preorderHelper(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorderHelper(root, ans);

        return ans;
        
    }
};
