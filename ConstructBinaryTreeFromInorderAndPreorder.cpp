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
    int findPos(int element, vector<int> &inorder){
        for(int i=0; i<inorder.size() ; i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;
    }
    TreeNode* buildTreeHelper(vector<int> & preorder, vector<int> &inorder, int &preIndex, int inorderStart, int inorderEnd){
        //base case
        if(preIndex>=preorder.size() || inorderStart>inorderEnd){
            return NULL;
        }
        
        //create root node
        int element=preorder[preIndex++];
        TreeNode* root=new TreeNode(element);

        int pos=findPos(element, inorder);
        //left child
        root->left=buildTreeHelper(preorder, inorder,preIndex, inorderStart, pos-1);
        //right child
        root->right=buildTreeHelper(preorder, inorder, preIndex, pos+1, inorderEnd);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex=0;
        int inorderStart=0;
        int inorderEnd=inorder.size()-1;
        TreeNode* ans=buildTreeHelper(preorder, inorder, preIndex, inorderStart, inorderEnd);

        return ans;

        
    }
};
