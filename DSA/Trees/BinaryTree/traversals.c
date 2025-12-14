//write a node structure for a binary tree and c functions to traverse the binary tree in inorder, postorder and preorder->

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;

void inorder(NODE *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(NODE *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

NODE* createNODE(int data){
    NODE *nn= (NODE*)malloc(sizeof(NODE));
    nn->data=data;
    nn->left = nn->right = NULL;
    return nn;
}

NODE *constructTree(){
    NODE *root=createNODE(1);
    root->left = createNODE(2);
    root->right = createNODE(3);

    root->left->left = createNODE(4);
    root->left->right = createNODE(5);

    return root;
}