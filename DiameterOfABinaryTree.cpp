class Solution {
public:
    int height(TreeNode* root){
        //base case
        if(root==NULL){
            return 0;
        }

        int left=height(root->left);
        int right=height(root->right);

        int ans=1+ max(left, right);
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //base case
        if(root==NULL){
            return 0;
        }

        //diameter can exist only in left part
        int op1=diameterOfBinaryTree(root->left);
        //diameter can exist only in right part
        int op2=diameterOfBinaryTree(root->right);
        //diameter can exist accross root
        int op3=(height(root->left) + height(root->right));

        //diameter is the maximum out of all
        int ans=max(op1, max(op2, op3));

        return ans;

        
    }
};
