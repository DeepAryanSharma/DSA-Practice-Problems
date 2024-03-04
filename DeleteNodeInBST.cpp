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
    int maxVal(TreeNode* root){
        if(root==NULL){
            return -1;
        }
        
        TreeNode* temp=root;
        while(temp->right!=NULL){
            temp=temp->right;
        }

        return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }

        //if current node is the node to be deleted
        if(root->val == key){
            //4-cases
            //case-1: if the node is leaf node
            if(root->left==NULL && root->right==NULL){
                return NULL;
            }

            //case-2: if the node has only left child
            if(root->right==NULL){
                TreeNode* child = root->left;
                return child;
            }

            //case-3: if node has only right child
            if(root->left==NULL){
                TreeNode* child=root->right;
                return child;
            }

            //case-4: if node has both left and right children
            if(root->left!=NULL && root->right!=NULL){
                //find inorder predecesor of the node
                int inorderPred=maxVal(root->left);
                //replace the data of the node with the data of its inorder predecessor
                root->val=inorderPred;
                //delete the inorder predecessor
                root->left=deleteNode(root->left, inorderPred);
            }
        }

        //if the current node value is greater then the key
        else if(root->val > key){
            //delete in left
            root->left=deleteNode(root->left, key);
        }
        else{
            //delete in right
            root->right=deleteNode(root->right, key);
        }

        return root;



        
    }
};
