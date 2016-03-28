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

bool bst::IsBst(){

     return IsBstUtil(root,INT_MAX,INT_MIN);
}

bool bst::IsBstUtil(Node *node,int max , int min){

     if(node == NULL)
          return true;

     if(node->data < min || node->data > max)
          return false;

     return
          IsBstUtil(node->left,node->data-1,min) &&
          IsBstUtil(node->right,max,node->data+1);

}

bst::Node *bst::MinValue(Node *node){

     Node *curr = node;
     while(curr->left)
          curr = curr->left;

     return curr;
}
bst::Node *bst::InorderSuccessor(Node *root, Node *node){
 
     if(node->right)
          return MinValue(node->right);

     Node *succ = NULL;
     while(root != NULL){
          if(node->data < root->data){
               succ = root;
               root = node->left;
          }
          else if(node->data > root->data)
               root = root->right;
           
          else
               break;
    }
    return succ;

}







    
