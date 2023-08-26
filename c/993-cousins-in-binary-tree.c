// https://leetcode.com/problems/cousins-in-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void getInfo(
    struct TreeNode *node,
    int target,
    int *depth,
    struct TreeNode **parent,
    bool *found
) {
    if (node == NULL) {
        return;
    }

    if (node->val == target) {
        *found = true;
        return;
    }

    if (!(*found)) *parent = node;

    if (!(*found)) (*depth)++;
    getInfo(node->left, target, depth, parent, found);

    if (!(*found)) *parent = node;
    getInfo(node->right, target, depth, parent, found);
    if (!(*found)) (*depth)--;
}

bool isCousins(struct TreeNode* root, int x, int y){
    bool found = false;
    int depthX = 0, depthY = 0;
    struct TreeNode *parentX = NULL;
    struct TreeNode *parentY = NULL;

    getInfo(root, x, &depthX, &parentX, &found);
    found = false;
    getInfo(root, y, &depthY, &parentY, &found);

    printf("%p %p ", parentX, parentY);
    printf("%d %d", depthX, depthY);

    if (parentX == parentY) return false;
    if (depthX == depthY) return true;
    return false;
}