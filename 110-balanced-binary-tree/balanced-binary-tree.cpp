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
class Solution{
public:
int f(TreeNode*r){
if(!r)return 0;
int l=f(r->left);
if(l==-1)return -1;
int rr=f(r->right);
if(rr==-1)return -1;
if(abs(l-rr)>1)return -1;
return max(l,rr)+1;
}
bool isBalanced(TreeNode*root){
return f(root)!=-1;
}
};