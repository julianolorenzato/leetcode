/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void recursiveSearch(struct TreeNode *node, int *values, int *index) {
    if (node == NULL) return;
    if (node->left != NULL) recursiveSearch(node->left, values, index);
    values[*index] = node->val;
    *index = *index + 1;
    if (node->right != NULL) recursiveSearch(node->right, values, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* values = (int*) malloc(sizeof(int) * 100);
    int index = 0;
    recursiveSearch(root, values, &index);
    *returnSize = index;
    return values;
}