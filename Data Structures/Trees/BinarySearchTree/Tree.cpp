#include <iostream>
#include "Tree.h"

#include <stack>
#include <queue>

using namespace std;

// Tree::TreeNode::TreeNode(const ElementType &data)
//     : data(data), left(NULL), right(NULL) {}

Tree::TreeNode::TreeNode(const ElementType &data)
    : data(data), left(NULL), right(NULL) {}

Tree::Tree() : root(NULL) {}

Tree::Tree(const Tree &other)
{
    if (other.root == NULL)
    {
        root = NULL;
    }
    else
    {
        root = new TreeNode(other.root->data);
        // copy everything recursively
        setNode(root, other.root);
    }
}

void Tree::setNode(NodePtr thisNode, NodePtr otherNode)
{
    if (otherNode != NULL)
    {
        if (otherNode->left == NULL)
        {
            thisNode->left = NULL;
        }
        else
        {
            thisNode->left = new TreeNode(otherNode->left->data);
        }

        if (otherNode->right == NULL)
        {
            thisNode->right = NULL;
        }
        else
        {
            thisNode->right = new TreeNode(otherNode->right->data);
        }

        setNode(thisNode->left, otherNode->left);
        setNode(thisNode->right, otherNode->right);
    }
}

Tree::~Tree()
{
    deleteFromNode(root);
}

void Tree::deleteFromNode(NodePtr r)
{
    if (r != NULL)
    {
        deleteFromNode(r->left);
        deleteFromNode(r->right);
        delete r;
    }
}

ElementType Tree::getRoot() const
{
    if (root != NULL)
        return root->data;

    ElementType garbage;
    return garbage;
}

bool Tree::isEmpty() const
{
    return root == NULL;
}

bool Tree::insert(const ElementType &e)
{
    if (root == NULL)
    {
        root = new TreeNode(e);
        return true;
    }
    // smaller, go left. bigger, go right, equal, return false

    NodePtr temp = root;
    NodePtr parent = NULL;
    while (temp != NULL)
    {
        parent = temp;
        if (e > temp->data) // go right
        {
            temp = temp->right;
        }
        else if (e < temp->data) // go left
        {
            temp = temp->left;
        }
        else // element is already in the tree.
        {
            return false;
        }
    }

    // temp is null, insert at parent->left or parent->right
    if (e > parent->data) // insert right
    {
        parent->right = new TreeNode(e);
    }
    else
    {
        parent->left = new TreeNode(e);
    }
    return true;
}

void Tree::inOrder(ostream &out) const // left, parent, right
{
    inOrderAux(out, root);
    out << endl;
}

void Tree::inOrderAux(ostream &out, NodePtr r) const
{
    if (r != NULL)
    {
        inOrderAux(out, r->left);
        out << r->data << " ";
        inOrderAux(out, r->right);
    }
}

void Tree::preOrder(ostream &out) const // parent, left, right
{
    preOrderAux(out, root);
    out << endl;
}

void Tree::preOrderAux(ostream &out, NodePtr r) const
{
    if (r != NULL)
    {
        out << r->data << " ";
        preOrderAux(out, r->left);
        preOrderAux(out, r->right);
    }
}

void Tree::postOrder(ostream &out) const // left, right, parent
{
    postOrderAux(out, root);
    out << endl;
}
void Tree::postOrderAux(ostream &out, NodePtr r) const
{
    if (r != NULL)
    {
        postOrderAux(out, r->left);
        postOrderAux(out, r->right);
        out << r->data << " ";
    }
}

int Tree::countNodes() const
{
    return countNodesAux(root);
}

int Tree::countNodesAux(NodePtr r) const
{
    if (r != NULL)
    {
        return 1 + countNodesAux(r->left) + countNodesAux(r->right);
    }
    return 0;
}

bool Tree::search(const ElementType &e) const
{
    NodePtr temp = root;
    while (temp != NULL)
    {
        if (e > temp->data)
        {
            temp = temp->right;
        }
        else if (e < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            return true;
        }
    }
    // Reached end of tree without finding element
    return false;
}

ElementType Tree::getSum() const
{
    return getSumAux(root);
}

ElementType Tree::getSumAux(NodePtr r) const
{
    if (r == NULL)
    {
        return 0;
    }
    return r->data + getSumAux(r->left) + getSumAux(r->right);
}

bool Tree::remove(const ElementType &e)
{
    // Find node
    NodePtr current = root;
    NodePtr parent = NULL;

    while (current != NULL && current->data != e)
    {
        parent = current;
        if (e > current->data)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }

    if (current == NULL) // could not find e
    {
        return false;
    }

    // current points to node we must delete, parent points to its parent
    if (current->left != NULL && current->right != NULL)
    {
        // Node containing e has two children
        NodePtr succ = current->right;
        parent = current;
        while (succ->left != NULL)
        {
            parent = succ;
            succ = succ->left;
        }
        current->data = succ->data;
        current = succ;
    }

    // current points to node we must delete, parent points to its parent
    // delete current

    // NOTE: current has ONLY ONE CHILD or no child
    // subTree points to the node after current
    NodePtr subTree = current->left; // pointer to a subtree of x
    if (subTree == NULL)
    {
        subTree = current->right;
    }
    // subtree now points to the only child of current (or NULL if no children)

    if (parent == NULL) // delete root node
    {
        root = subTree;
    }
    else if (parent->left == current)
    {
        parent->left = subTree;
    }
    else
    {
        parent->right = subTree;
    }

    delete current;
    return true;
}

ostream &operator<<(ostream &out, const Tree &tree)
{
    tree.inOrder(out);
    return out;
}

// Book exercises - Page 697 (112/191 in PDF)

// Ex 22
int Tree::level(const ElementType &e) const
{
    return levelAux(e, root);
}

int Tree::levelAux(const ElementType &e, NodePtr r) const
{
    if (r == NULL)
    {
        return -1; // Not found
    }

    if (e == r->data)
    {
        return 0;
    }
    int sublevel;
    if (e > r->data)
    {
        sublevel = levelAux(e, r->right);
    }
    sublevel = levelAux(e, r->left);

    if (sublevel == -1)
    {
        return -1; // not found
    }
    return sublevel + 1;
}

// Ex 23
int Tree::levelIterative(const ElementType &e) const
{
    if (root == NULL)
    {
        return -1;
    }

    NodePtr temp = root;
    int level = 0;

    while (temp != NULL)
    {
        if (e == temp->data)
        {
            return level;
        }

        if (e > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
        level++;
    }

    return -1; // not found
}

// Ex 24
int Tree::height() const
{
    return heightAux(root);
}

int Tree::heightAux(NodePtr r) const
{
    if (r == NULL)
    {
        return -1;
    }
    int left = 1 + heightAux(r->left);
    int right = 1 + heightAux(r->right);

    if (left > right)
    {
        return left;
    }
    return right;
}

// Ex 25
int Tree::leafCount() const
{
    return leafCountAux(root);
}

int Tree::leafCountAux(NodePtr r) const
{
    if (r == NULL)
    {
        return 0;
    }
    if (r->left == NULL && r->right == NULL)
    {
        return 1;
    }
    return leafCountAux(r->left) + leafCountAux(r->right);
}

// Ex 26
void Tree::inOrderIterative(ostream &out) const
{
    stack<NodePtr> nodeStack;
    NodePtr temp = root;

    while (temp != NULL || !nodeStack.empty()) // stop only when temp is null and nodeStack is empty
    {
        while (temp != NULL)
        {
            nodeStack.push(temp);
            temp = temp->left;
        }

        temp = nodeStack.top();
        out << temp->data << " ";

        nodeStack.pop();

        temp = temp->right;
    }
}

// Ex 27
void Tree::levelByLevel(std::ostream &out) const
{
    // Each pass through the loop, dequeue parent, print it, then enqueue left and right children
    // Queue must be 'emptied' every pass (loop from 0 to initial size)

    if (root == NULL)
    {
        return;
    }
    queue<NodePtr> nodeQueue;

    nodeQueue.push(root);
    NodePtr temp;
    int level = 0;

    while (!nodeQueue.empty())
    {
        out << "Level " << level++ << ": ";
        for (int i = 0, len = nodeQueue.size(); i < len; i++)
        {
            temp = nodeQueue.front();
            nodeQueue.pop();

            out << temp->data << " ";
            if (temp->left != NULL)
                nodeQueue.push(temp->left);

            if (temp->right != NULL)
                nodeQueue.push(temp->right);
        }
        out << endl;
    }
}

// Ex 28
bool Tree::removeRecursive(const ElementType &e)
{
    return removeRecursiveAux(e, root, NULL);
}

bool Tree::removeRecursiveAux(const ElementType &e, NodePtr current, NodePtr parent)
{
    if (current == NULL)
        return false;

    if (e > current->data)
        return removeRecursiveAux(e, current->right, current);

    if (e < current->data)
        return removeRecursiveAux(e, current->left, current);

    // current points to the node to delete
    if (current->left != NULL && current->right != NULL)
    {
        NodePtr succ = current->right;
        parent = current;
        while (succ->left != NULL)
        {
            parent = succ;
            succ = succ->left;
        }
        current->data = succ->data;
        return removeRecursiveAux(succ->data, succ, parent);
    }

    // one child or no children
    NodePtr subtree = current->left ? current->left : current->right;
    if (parent == NULL)
    {
        root = subtree;
    }
    else if (parent->left == current)
    {
        parent->left = subtree;
    }
    else
    {
        parent->right = subtree;
    }

    delete current;
    return true;
}
