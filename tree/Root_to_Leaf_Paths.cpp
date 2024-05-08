//problem link - https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

class Solution {
  public:
   void solve(Node* root,vector<vector<int>> &ans,vector<int> &out){
        if(root==NULL){
           return;
       }
        int data = root->data;
       out.push_back(data);
       if(root->right==NULL && root->left==NULL){
           ans.push_back(out);
       }
      
      
       solve(root->left,ans,out);
       solve(root->right,ans,out);
        out.pop_back();
      
      
   }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> out;
        solve(root,ans,out);
        return ans;
    }
};