//print all root to leaf paths in a binary search tree

#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
typedef struct Node NODE;
NODE* createNode(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
NODE* insert(NODE* root, int data) {
    if(root == NULL) {
        return createNode(data);
    }
    if(data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}
void printPathsRecur(NODE* root, int path[], int pathLen) {
    if(root == NULL) {
        return;
    }
    path[pathLen] = root->data;
    pathLen++;
    if(root->left == NULL && root->right == NULL) {
        for(int i = 0; i < pathLen; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        printPathsRecur(root->left, path, pathLen);
        printPathsRecur(root->right, path, pathLen);
    }
}
void printPaths(NODE* root) {
    int path[1000];
    printPathsRecur(root, path, 0);
}
int main() {
    NODE* root = NULL;
    int n, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d node values:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("Root to leaf paths in BST:\n");
    printPaths(root);
    return 0;
}

/*
Enter number of nodes: 7 
Enter 7 node values:
34 11 57 33 27 37 45
Root to leaf paths in BST:
34 11 33 27
34 57 37 45
*/