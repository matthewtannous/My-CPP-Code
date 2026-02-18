#ifndef TREE_H
#define TREE_H

#include <iostream>

typedef int ElementType;

class Tree
{
private:
    class TreeNode
    {
    public:
        TreeNode(const ElementType &data);
        ElementType data;
        TreeNode *left,
            *right;
    };
    typedef TreeNode *NodePtr;

public:
    Tree();
    Tree(const Tree &other);
    ~Tree();

    // Tree &operator=(const Tree &other);

    ElementType getRoot() const;

    bool isEmpty() const;

    bool insert(const ElementType &e);

    void inOrder(std::ostream &out) const;
    void preOrder(std::ostream &out) const;
    void postOrder(std::ostream &out) const;

    int countNodes() const;

    bool search(const ElementType &e) const;

    ElementType getSum() const;

    bool remove(const ElementType &e);

    // Book exercises (image)

    int level(const ElementType &e) const;          // Ex 22
    int levelIterative(const ElementType &e) const; // Ex 23

    int height() const;    // Ex 24
    int leafCount() const; // Ex 25

    void inOrderIterative(std::ostream &out) const; // Ex 26

    void levelByLevel(std::ostream &out) const; // Ex 27

    bool removeRecursive(const ElementType &e); // Ex 28

private:
    NodePtr root;
    void inOrderAux(std::ostream &out, NodePtr r) const;
    void preOrderAux(std::ostream &out, NodePtr r) const;
    void postOrderAux(std::ostream &out, NodePtr r) const;

    int countNodesAux(NodePtr r) const;
    ElementType getSumAux(NodePtr r) const;

    void deleteFromNode(NodePtr r);

    void setNode(NodePtr thisNode, NodePtr otherNode);

    // Book exercices (image)

    int levelAux(const ElementType &e, NodePtr r) const;                            // Ex 22
    int heightAux(NodePtr r) const;                                                 // Ex 24
    int leafCountAux(NodePtr r) const;                                              // Ex 25
    bool removeRecursiveAux(const ElementType &e, NodePtr current, NodePtr parent); // Ex 28
};

std::ostream &operator<<(std::ostream &out, const Tree &tree);

#endif
