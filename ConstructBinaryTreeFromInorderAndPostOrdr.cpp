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
    TreeNode* buildTreeHelper(vector<int> &inorder, vector<int> &postorder, int &postIndex, int inorderStart, int inorderEnd){
        //base case
        if(postIndex<0 || inorderStart>inorderEnd){
            return NULL;
        }
        
        //create root node
        int element=postorder[postIndex--];
        TreeNode* root=new TreeNode(element);

        int pos=findPos(element, inorder);
        //right child
        root->right=buildTreeHelper(inorder, postorder, postIndex, pos+1, inorderEnd);
        //left child
        root->left=buildTreeHelper(inorder, postorder,postIndex, inorderStart, pos-1);
       
       

        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex=postorder.size()-1;
        int inorderStart=0;
        int inorderEnd=inorder.size()-1;
        TreeNode* ans=buildTreeHelper(inorder, postorder, postIndex, inorderStart, inorderEnd);

        return ans;

        
    }
};
