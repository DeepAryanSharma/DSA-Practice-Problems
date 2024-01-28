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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int, int>>>q; // Node, {row, col};
        q.push({root, {0,0}}); //initially
        map<int, map<int, multiset<int>>> mp; // col-> row: {x,y,z.....}
        
        while(!q.empty()){
            auto front=q.front();
            q.pop();

            TreeNode* temp=front.first;
            auto cordinates=front.second;
            int row=cordinates.first;
            int col=cordinates.second;
            mp[col][row].insert(temp->val);

            //if left exists
            if(temp->left){
                q.push({temp->left, {row+1, col-1}});
            }
            //if right exists
            if(temp->right){
                q.push({temp->right, {row+1, col+1}});
            }
        }

        //insert the final vertical order in the answer vector
        for(auto it:mp){
            auto colmp=it.second;
            vector<int> vline;
            for(auto colmpit: colmp){
                auto elementset=colmpit.second;
                vline.insert(vline.end(), elementset.begin(), elementset.end());
            }

            ans.push_back(vline);
        }

        return ans;
    }
};
