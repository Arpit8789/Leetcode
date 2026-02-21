class Solution {
public:
    TreeNode* solve(TreeNode* root,int key)
    {
        if(root == NULL)
            return NULL;

        if(key < root->val)
        {
            root->left = solve(root->left, key);
        }
        else if(key > root->val)
        {
            root->right = solve(root->right, key);
        }
        else
        {
            // Case 1: No child
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }

            // Case 2: One child
            if(root->left == NULL)
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if(root->right == NULL)
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            TreeNode* temp = root->right;
            while(temp->left != NULL)
                temp = temp->left;

            root->val = temp->val;
            root->right = solve(root->right, temp->val);
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return solve(root,key);
    }
};