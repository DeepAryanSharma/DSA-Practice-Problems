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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }

        queue<TreeNode*> q;
        //initially
        q.push(root);

        bool LtoR=true;
        while(!q.empty()){
            int width=q.size();
            vector<int> onelevel(width);
            int index;
            //inserting the values of node in the vector according to the direction
            for(int i=0 ; i<width ; i++){
                TreeNode* temp=q.front();
                q.pop();
                if(LtoR){
                    index=i;
                }
                else{
                    index=width-i-1;
                }
                onelevel[index]=temp->val;
                //push to childeren of the node in the queue
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }

            //toggle the direction
            LtoR= !LtoR;
            
            //push the level vector in the answer
            ans.push_back(onelevel);

        }

        return ans;
        
    }
};
