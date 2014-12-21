#include<iostream>

using namespace std;

#include "bst.h"

bst::bst():root(NULL) { }

bst::~bst(){ }
void bst::BuildTree(int key)

{
  if(root == NULL)
   {
     cout << "First node here: " << endl;
     root = new Node;
     root->data = key;
     root->left = NULL;
     root->right = NULL;
   }

   BuildTreeUtil(root,key);
}     

void bst::BuildTreeUtil(Node *node, int key)

{

   if(key < node->data )

    {
      //Left node 
      if(!node->left)

        {
           node->left = new Node;
           node->left->data = key;
           node->left->left = NULL;
           node->left->right = NULL;      
        }

     else
        BuildTreeUtil(node->left,key);
    }

  else if(key > node->data)

   {
      if(!node->right)

       {
         node->right = new Node; 
         node->right->data = key;
         node->right->left = NULL;
         node->right->right = NULL; 
       }
   
      else
        BuildTreeUtil(node->right,key);

   }

}

void bst::PrintInorder()

{
  if(root == NULL)
    return;

  PrintInorderUtil(root);
}

void bst::PrintInorderUtil(Node *node)

{

   if(node == NULL)

    return;
 
   PrintInorderUtil(node->left);

   cout << node->data << endl;

   PrintInorderUtil(node->right);

}
    
