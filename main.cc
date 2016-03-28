#include<iostream>
#include "bst.h"

using namespace std;

 
int main()

{

  bst b1;

  b1.BuildTree(20);
  b1.BuildTree(8);
  b1.BuildTree(22);
  b1.BuildTree(4);
  b1.BuildTree(12);
  b1.BuildTree(10);
  b1.BuildTree(14);
 
  b1.PrintInorder();
  if(b1.IsBst())
       cout << "Tree is BST: " << "\n";
  else
       cout << "Tree is not BST: " << "\n";

  bst::Node *tmp =  b1.root->left;
  bst::Node *succ = b1.InorderSuccessor(b1.root,tmp);
  if(succ != NULL)
       cout << "Inorder successor is: " << succ->data << "\n";


  return 0;

}
