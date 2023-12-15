class Solution {
public:
    int maxDepth(TreeNode* root) {
        //base case
        if(root==NULL){
            return 0;
        }

        //leftHeight
        int leftHeight=maxDepth(root->left);
        //rightHeight
        int rightHeight=maxDepth(root->right);

        int ans=1 + max(leftHeight,rightHeight);

        return ans;
        
    }
};
