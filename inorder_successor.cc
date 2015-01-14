#include<iostream>
using namespace std;

struct Node{

     int data;
     Node *left;
     Node *right;
};

class Bst{

public:

     Bst(){}
    ~Bst(){}
    Node *AddNode(Node *tnode,int data);
    Node *NewNode(int data);
    void PrintTree(Node *node);
};

Node *Bst::NewNode(int data)
{

     Node *node = new Node;
     node->data = data;
     node->left = NULL;
     node->right = NULL;
}

Node *Bst::AddNode(Node *tnode, int data)
{

     //if  the tree is empty, make a root node
     if(tnode == NULL)
     {
          return(NewNode(data));
     }
     else if(tnode->data < data)
     {
          if(tnode->right == NULL)
          {    
              // cout << "constructed first right node:" << endl; 
               tnode->right = NewNode(data);
          }
          else
          {
               AddNode(tnode->right,data);
          }
     }
     else if(tnode->data > data)
     {
          if(tnode->left == NULL)
          {
             //  cout << "Constructed first left node:" << endl;
               tnode->left = NewNode(data);
          }
          else
          {
               AddNode(tnode->left, data);
          }
     }
     return tnode;
     
}
  
void Bst::PrintTree(Node *node)
{

     if(!node)
          return;
     PrintTree(node->left);
     cout << node->data<<"\t";
     PrintTree(node->right);
}

int main()
{

     Bst b1;
     Node *root = NULL, *succ;
     root = b1.AddNode(root,20);
     root = b1.AddNode(root,8);
     root = b1.AddNode(root,22);
     root = b1.AddNode(root,4);
     root = b1.AddNode(root,12);
     root = b1.AddNode(root,10);
     root = b1.AddNode(root,14);
     if(root)
     {
          cout << "Added root node:" << endl;
          cout << "data at root node is:" << root->data << endl;
     }
     b1.PrintTree(root);
     cout << "\n";
     return 0;

}
    
