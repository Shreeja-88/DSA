//Given the head of a single linked list find the middle node of the LinkedIn list if the number of node is odd return the middle node, if the number of nodes is even there are 2 middle nodes, so return the second middle node

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* findMiddle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Move fast two steps and slow one step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;  
}

int main() {
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);

    struct Node* mid = findMiddle(head);
    printf("Middle node: %d\n", mid->data);

    return 0;
}
