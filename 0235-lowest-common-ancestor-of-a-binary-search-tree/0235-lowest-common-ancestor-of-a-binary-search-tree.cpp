class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        while (root != NULL) {
            
            // Both nodes lie in left subtree
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            
            // Both nodes lie in right subtree
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            
            // Split happens OR one equals root
            else {
                return root;
            }
        }
        
        return NULL; // safety return
    }
};