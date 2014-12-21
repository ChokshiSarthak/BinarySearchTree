#include<iostream>

class Btree{

 private:
      struct Node{
           int data;
           Node *right;
           Node *left;
         }*root;

     
    void BuildBinaryTree(Node *node, int key);

    void PrintInorder(Node *node);

public:
     Btree();

    ~Btree();

     void BuildTree(int key);
     void PrintInorder();

 };

Btree::Btree():root(NULL){}

Btree::~Btree(){}

void Btree::BuildTree(int key)
{
     if(root == NULL)
     {
          root = new Node;
          root->data = key;
          root->left = NULL;
          root->right = NULL;
     }
     BuildBinaryTree(root,key);

}

void Btree::BuildBinaryTree(Node *node, int key)
{
     if(key < node->data)
     {
          //left node
          if(!node->left)
          {
               node->left = new Node;
               node->left->data = key;
               node->left->left = NULL;
               node->left->right = NULL;

          }
         else
         {
               BuildBinaryTree(node->left,key);
         }
     }

      else if(key > node->data)
      {
           if(!node->right)
           {
                node->right = new Node;
                node->right->data = key;
                node->right->right = NULL;
                node->right->left = NULL;
           }
           else
           {
                BuildBinaryTree(node->right,key);

           }

      }

}

void Btree::PrintInorder()
{
     if(!root) return;
 
     PrintInorder(root);

}

void Btree::PrintInorder(Node *node)
{
     if(node == NULL) 
          return;
  
     PrintInorder(node->left);
     
     std::cout << node->data << std::endl;
 
     PrintInorder(node->right);
}



int main()
{
  Btree b1;
  b1.BuildTree(9);
  b1.BuildTree(12);
  b1.BuildTree(7);
  b1.BuildTree(8);
  b1.BuildTree(6);
  b1.BuildTree(13);
  b1.BuildTree(10);

  b1.PrintInorder();
  return 0;

}
               
    
 



     
