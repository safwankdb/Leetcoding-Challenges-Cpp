#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    // Find y in subtree x
    bool dfs(TreeNode* x, TreeNode* y) {
        if (x == NULL)
            return false;
        else if (x == y)
            return true;
        else if (dfs(x->left, y))
            return true;
        else if (dfs(x->right, y))
            return true;
        else
            return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q,
                                   bool check = true) {
        if (check)
            if (dfs(p, q))
                return p;
            else if (dfs(q, p))
                return q;
        if (dfs(root->left, p))
            if (dfs(root->left, q))
                return lowestCommonAncestor(root->left, p, q, false);
            else
                return root;
        else if (dfs(root->left, q))
            return root;
        else
            return lowestCommonAncestor(root->right, p, q, false);
    }
};