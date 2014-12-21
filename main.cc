#include<iostream>
#include "bst.h"

using namespace std;

 
int main()

{

  bst b1;

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
