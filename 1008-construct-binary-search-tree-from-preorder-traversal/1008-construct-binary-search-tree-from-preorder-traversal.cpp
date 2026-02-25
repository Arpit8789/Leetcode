class Solution {
public:
    
    TreeNode* build(vector<int>& preorder, int& index, int minVal, int maxVal) {
        
        // Base condition
        if (index >= preorder.size())
            return NULL;
        
        int val = preorder[index];
        
        if (val <= minVal || val >= maxVal)
            return NULL;
        
        // Create node
        TreeNode* root = new TreeNode(val);
        index++;
        
        // Build left subtree
        root->left = build(preorder, index, minVal, val);
        
        // Build right subtree
        root->right = build(preorder, index, val, maxVal);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return build(preorder, index, INT_MIN, INT_MAX);
    }
};