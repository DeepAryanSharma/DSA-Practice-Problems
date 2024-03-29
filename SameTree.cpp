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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //base case
        //if both of them are or become null
        if(p==NULL && q==NULL){
            return true;
        }

        //if both of them are not null
        if(p && q){
            return (p->val==q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }

        //if anyone of them is null
        return NULL;
        
    }
};
