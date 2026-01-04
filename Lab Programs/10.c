//Implement a queue using arrays with opeartions insertrear, deletefront and display
#include <stdio.h>
int MAX, queue[100];
int front = -1, rear = -1;
void enqueue(int );
void dequeue();
void display();

int main() {
    int choice, num;
    printf("Enter the size of the queue: ");
    scanf("%d", &MAX);
    while(1) {
        printf("\n1. Insert at rear\n2. Delete at front\n3. Display\n4. Stop\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &num);
                enqueue(num);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
void enqueue(int n) {
    if(rear==MAX-1) {
        printf("Queue Overflow\n");
        return;
    }
    else if(rear==-1 && front == -1) {
        front = rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = n;
}

void dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Item deleted: %d\n", queue[front]);
    front++;
    if(front > rear) {
        front = rear = -1;
    }
}
void display() {
    if(front == -1 || front > rear) {
        printf("Queue Empty\n");
        return;
    }
    printf("Queue elements: ");
    for(int i=front; i<=rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

/*
Enter the size of the queue: 5

1. Insert at rear
2. Delete at front
3. Display
4. Stop
Enter your choice: 1
Enter data to insert: 4

1. Insert at rear
2. Delete at front
3. Display
4. Stop
Enter your choice: 1
Enter data to insert: 2

1. Insert at rear
2. Delete at front
3. Display
4. Stop
Enter your choice: 1
Enter data to insert: 2

1. Insert at rear
2. Delete at front
3. Display
4. Stop
Enter your choice: 3
Queue elements: 4 2 2 

1. Insert at rear
2. Delete at front
3. Display
4. Stop
Enter your choice: 2
Item deleted: 4

1. Insert at rear
2. Delete at front
3. Display
4. Stop
Enter your choice: 2
Item deleted: 2

1. Insert at rear
2. Delete at front
3. Display
4. Stop
Enter your choice: 4
*/