/*Program to construct a binary search tree from inorder and preorder traversal. */
#include<stdio.h>
#include<stdlib.h>

struct node{

     char data;
     struct node *left;
     struct node *right;
};

int search(char in[],int start,int end,char value)
{
     int i;
     for(i=start; i<= end; i++)
     {
          if(in[i] == value)
               return i;
     }
}

struct node *newNode(char data)
{
     struct node *node = (struct node*)malloc (sizeof(struct node));
     if(node)
     {
          node->data = data;
          node->left = NULL;
          node->right = NULL;
     }
     return node;
}

struct node* BuildTree(char in[], char pre[],int inStart, int inEnd)
{    
    
     static int preIndex = 0;
     if(inStart > inEnd)
          return NULL;

     struct node *tnode = newNode(pre[preIndex++]);
     if(inStart == inEnd)
          return tnode;
     int inIndex = search(in,inStart,inEnd,tnode->data);
     tnode->left = BuildTree(in,pre,inStart,inIndex-1);
     tnode->right = BuildTree(in,pre,inIndex+1,inEnd);
     
     return tnode;
}     

void PrintTree(struct node *node)
{
     if(node == NULL)
          return;
   
     PrintTree(node->left);
     printf("%c",node->data);
     PrintTree(node->right);
    
}

int main()
{
     char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
     char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
     int len = sizeof(in)/sizeof(in[0]); 
     struct node *root = BuildTree(in,pre,0,len-1);
     PrintTree(root);
     printf("\n");
     return 0;
}



