#ifndef BST_H
#define BST_H

class bst {

 private:
    struct Node 

    {  
       Node *left;
       Node *right;
       int data;
    }*root;

    void BuildTreeUtil(Node *node, int key);  
    void PrintInorderUtil(Node *node);
public:
     bst();

    ~bst();

    void BuildTree(int key);
    void PrintInorder();

 };

#endif
