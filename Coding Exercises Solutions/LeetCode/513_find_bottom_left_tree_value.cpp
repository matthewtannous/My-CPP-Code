int findBottomLeftValue(TreeNode *root)
{
    // go level by level until only one node has a left child
    // keep going left (check if you arrive at a node that has 2 children after)

    queue<TreeNode *> q;
    q.push(root);
    int leftmost;

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        leftmost = node->val;

        if (node->right != nullptr) // push right first so that last extracted
                                    // value is a left node
        {
            q.push(node->right);
        }
        if (node->left != nullptr)
        {
            q.push(node->left);
        }
    }
    return leftmost;
}