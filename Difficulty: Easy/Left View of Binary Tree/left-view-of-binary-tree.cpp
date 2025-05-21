class Solution {
  public:
    void leftViewTree(Node *root,int level,vector<int> &ans){
        if(root==NULL)
        return;
        if(level==ans.size())
        ans.push_back(root->data);
        leftViewTree(root->left,level+1,ans);
        leftViewTree(root->right,level+1,ans);
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        leftViewTree(root,0,ans);
        return ans;
    }
};