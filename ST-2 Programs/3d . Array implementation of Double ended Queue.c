#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Deque {
    int front, rear;
    int array[MAX_SIZE];
};

void initializeDeque(struct Deque* deque) {
    deque->front = -1;
    deque->rear = -1;
}

int isFull(struct Deque* deque) {
    return ((deque->front == 0 && deque->rear == MAX_SIZE - 1) || (deque->front == deque->rear + 1));
}

int isEmpty(struct Deque* deque) {
    return (deque->front == -1);
}

void insertFront(struct Deque* deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert %d at the front\n", value);
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = MAX_SIZE - 1;
    } else {
        deque->front--;
    }

    deque->array[deque->front] = value;
    printf("%d inserted at the front of the deque\n", value);
}

void insertRear(struct Deque* deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert %d at the rear\n", value);
        return;
    }

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->rear == MAX_SIZE - 1) {
        deque->rear = 0;
    } else {
        deque->rear++;
    }

    deque->array[deque->rear] = value;
    printf("%d inserted at the rear of the deque\n", value);
}

int deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from the front\n");
        return -1;
    }

    int value = deque->array[deque->front];

    if (deque->front == deque->rear) {
        // Last element in the deque
        deque->front = -1;
        deque->rear = -1;
    } else {
        if (deque->front == MAX_SIZE - 1) {
            deque->front = 0;
        } else {
            deque->front++;
        }
    }

    printf("%d deleted from the front of the deque\n", value);
    return value;
}

int deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from the rear\n");
        return -1;
    }

    int value = deque->array[deque->rear];

    if (deque->front == deque->rear) {
        // Last element in the deque
        deque->front = -1;
        deque->rear = -1;
    } else {
        if (deque->rear == 0) {
            deque->rear = MAX_SIZE - 1;
        } else {
            deque->rear--;
        }
    }

    printf("%d deleted from the rear of the deque\n", value);
    return value;
}

void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    int i = deque->front;
    do {
        printf("%d ", deque->array[i]);
        if (i == deque->rear)
            break;
        i = (i + 1) % MAX_SIZE;
    } while (1);

    printf("\n");
}

int main() {
    struct Deque myDeque;
    initializeDeque(&myDeque);

    int choice, value;

    do {
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the front: ");
                scanf("%d", &value);
                insertFront(&myDeque, value);
                break;
            case 2:
                printf("Enter the value to insert at the rear: ");
                scanf("%d", &value);
                insertRear(&myDeque, value);
                break;
            case 3:
                deleteFront(&myDeque);
                break;
            case 4:
                deleteRear(&myDeque);
                break;
            case 5:
                display(&myDeque);
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
