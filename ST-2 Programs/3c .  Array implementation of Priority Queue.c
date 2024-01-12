#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct PriorityQueue {
    int front;
    int rear;
    int elements[MAX_SIZE];
    int priorities[MAX_SIZE];
};

void initializePriorityQueue(struct PriorityQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(struct PriorityQueue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

int isEmpty(struct PriorityQueue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

void enqueue(struct PriorityQueue* queue, int element, int priority) {
    if (isFull(queue)) {
        printf("Priority Queue is full. Cannot enqueue %d with priority %d\n", element, priority);
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        int i;
        for (i = queue->rear; i >= queue->front; --i) {
            if (priority > queue->priorities[i]) {
                queue->elements[i + 1] = queue->elements[i];
                queue->priorities[i + 1] = queue->priorities[i];
            } else {
                break;
            }
        }
        queue->rear = i + 1;
    }

    queue->elements[queue->rear] = element;
    queue->priorities[queue->rear] = priority;
    printf("%d enqueued to the priority queue with priority %d\n", element, priority);
}

int dequeue(struct PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Priority Queue is empty. Cannot dequeue\n");
        return -1;
    }

    int element = queue->elements[queue->front];
    int priority = queue->priorities[queue->front];

    if (queue->front == queue->rear) {
        // Last element in the queue
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }

    printf("%d dequeued from the priority queue with priority %d\n", element, priority);
    return element;
}

void display(struct PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue elements:\n");
    for (int i = queue->front; i <= queue->rear; ++i) {
        printf("%d (Priority: %d)\n", queue->elements[i], queue->priorities[i]);
    }
}

int main() {
    struct PriorityQueue myPriorityQueue;
    initializePriorityQueue(&myPriorityQueue);

    int choice, element, priority;

    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                printf("Enter the priority for the element: ");
                scanf("%d", &priority);
                enqueue(&myPriorityQueue, element, priority);
                break;
            case 2:
                dequeue(&myPriorityQueue);
                break;
            case 3:
                display(&myPriorityQueue);
                break;
            case 0:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
