//Create a Linked list of 5 numbers, insert a new number if the number is multiple of 5 Insert at the end of the list otherwise insert at 2nd position. & Dlt all the multiples of 3 from the list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->next = NULL;
    return n;
}

void insertAtEnd(struct Node **head, int val) {
    struct Node* n = createNode(val);
    if (*head == NULL) {
        *head = n;
        return;
    }
    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = n;
}

void insertAtSecond(struct Node **head, int val) {
    struct Node* n = createNode(val);
    if (*head == NULL) {
        *head = n;
        return;
    }
    n->next = (*head)->next;
    (*head)->next = n;
}

void deleteMultiplesOf3(struct Node **head) {
    struct Node *temp = *head, *prev = NULL;

    while (temp != NULL) {
        if (temp->data % 3 == 0) {
            if (prev == NULL) {
                *head = temp->next;
                free(temp);
                temp = *head;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int val;

    printf("Enter 5 numbers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &val);
        insertAtEnd(&head, val);
    }

    printf("Enter a new number to insert: ");
    scanf("%d", &val);

    if (val % 5 == 0)
        insertAtEnd(&head, val);
    else
        insertAtSecond(&head, val);

    printf("List after insertion:\n");
    printList(head);

    deleteMultiplesOf3(&head);

    printf("List after deleting multiples of 3:\n");
    printList(head);

    return 0;
}
