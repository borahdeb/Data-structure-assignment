#include <stdio.h>
#define MAX 5

int cqueue_arr[MAX];
int front = -1; // Queue is empty initially
int rear = -1;  // Queue is empty initially

void insert(int item) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) { // Insert the first element
        front = 0;
        rear = 0;
    } else {
        if (rear == MAX - 1) // Circular increment
            rear = 0;
        else
            rear = rear + 1;
    }
    cqueue_arr[rear] = item;
}

void delete() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue is: %d\n", cqueue_arr[front]);
    if (front == rear) { // Queue has only one element
        front = -1;
        rear = -1;
    } else {
        if (front == MAX - 1) // Circular increment
            front = 0;
        else
            front = front + 1;
    }
}

void display() {
    int front_pos = front, rear_pos = rear;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    if (front_pos <= rear_pos) {
        while (front_pos <= rear_pos) {
            printf("%d ", cqueue_arr[front_pos]);
            front_pos++;
        }
    } else {
        while (front_pos <= MAX - 1) {
            printf("%d ", cqueue_arr[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while (front_pos <= rear_pos) {
            printf("%d ", cqueue_arr[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}

int main() {
    int choice, item;
    do {
        printf("\nCircular Queue Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Input the element for insertion in queue: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Wrong choice\n");
        }
    } while (choice != 4);

    return 0;
}