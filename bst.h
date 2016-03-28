#ifndef BST_H
#define BST_H

#include<limits.h>
class bst {

public:
    struct Node 

    {  
       Node *left;
       Node *right;
       int data;
    };

    Node *root;
    void BuildTreeUtil(Node *node, int key);  
    void PrintInorderUtil(Node *node);
    bool IsBstUtil(Node *node,int max, int min);
     bst();

    ~bst();

    
    void BuildTree(int key);
    void PrintInorder();
    bool IsBst();
    Node *MinValue(Node *node);
    Node *InorderSuccessor(Node *root, Node *node);

 };

#endif
