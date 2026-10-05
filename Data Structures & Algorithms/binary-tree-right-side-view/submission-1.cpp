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
    vector<int> bfs(TreeNode* node){

        queue<TreeNode*> q;
        q.push(node);
        vector<int> ans;

        while(!q.empty()){
            int len=q.size();
            
            for(int i =0;i<len;i++){
                TreeNode* curr_node=q.front();
                q.pop();
                if(i==len-1){
                    ans.push_back(curr_node->val);
                }
                if(curr_node->left!=NULL){
                    q.push(curr_node->left);
                }

                if(curr_node->right!=NULL){
                    q.push(curr_node->right);
                }
            }
        }
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        return bfs(root);
    }
};
