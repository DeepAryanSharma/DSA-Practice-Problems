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
    void solve(TreeNode* root, int &targetSum, int &sum, bool &ans){
        //base case
        if(root== NULL){
            return;
        }

        //for leaf node
        if(root->left == NULL && root->right==NULL){
            //include the node
            sum += root->val;
            //check of targetSum
            if(sum==targetSum){
                ans= true;
            }

            //exclude the node
            sum -= root->val;
            return;
        }

        //for rest of the nodes
        //include the node
        sum += root->val;

        //recursive calls on left and right children
        solve(root->left, targetSum, sum, ans);
        solve(root->right, targetSum, sum, ans);

        //backtrack
        sum -= root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans=false;
        int sum=0;
        solve(root, targetSum, sum, ans);
        
        return ans;
    }
};
