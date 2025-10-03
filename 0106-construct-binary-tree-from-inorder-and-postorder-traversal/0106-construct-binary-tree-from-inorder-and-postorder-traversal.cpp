

class Solution {
public:
    unordered_map<int, int> value_index_map; // value -> index in inorder

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder,
                              int inStart, int inEnd, int& postIndex) {
        // Base case: no elements
        if (inStart > inEnd) return nullptr;

        // Step 1: Pick current root from postorder
        int rootVal = postorder[postIndex];
        TreeNode* root = new TreeNode(rootVal);
        postIndex--;

        // Step 2: Find root index in inorder using hash map
        int inIndex = value_index_map[rootVal];

        // Step 3: Recursively build right and left subtrees
        root->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd, postIndex);
        root->left  = buildTreeHelper(inorder, postorder, inStart, inIndex - 1, postIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postIndex = n - 1;

        // Fill hash map: value -> index in inorder
        for (int i = 0; i < n; i++) {
            value_index_map[inorder[i]] = i;
        }

        return buildTreeHelper(inorder, postorder, 0, n - 1, postIndex);
    }
};
