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
    void fill_vector(vector<int>& vec , TreeNode* root){
        if(root){
            fill_vector(vec ,root->left);
            vec.push_back(root->val);
            fill_vector(vec ,root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) {
       vector<int> values;
        fill_vector(values,root);
        int i = 0 , j = values.size()-1;
        while(values[i]+values[j]!=k){
            if(values[i]+values[j]<k)
                i++;
            else
                j--;
            
            if(i>=j)
                return false;
        }
        if(i>=j)
            return false;
        return true ;
    }
};