#include <stdio.h>
#include <stdlib.h>

// Node structure for a circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the circular linked list
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode; // Point to itself for a single node circular list
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    return head;
}

// Function to insert a node at the end of the circular linked list
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode; // Point to itself for a single node circular list
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    return head;
}

// Function to delete a node from the beginning of the circular linked list
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = head;
        struct Node* lastNode = head;

        while (lastNode->next != head) {
            lastNode = lastNode->next;
        }

        if (head == head->next) {
            // Only one node in the list
            free(head);
            head = NULL;
        } else {
            head = head->next;
            lastNode->next = head;
            free(temp);
        }
    }

    return head;
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = head;
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("(head)\n");
    }
}

// Function to free the memory allocated for the circular linked list
void freeList(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* temp;
    struct Node* current = head;

    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != head);
}

int main() {
    struct Node* list = NULL;
    int value, choice;

    do {
        // Display menu
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at the Beginning\n");
        printf("2. Insert at the End\n");
        printf("3. Delete from the Beginning\n");
        printf("4. Display List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                list = insertAtBeginning(list, value);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                list = insertAtEnd(list, value);
                break;
            case 3:
                list = deleteFromBeginning(list);
                break;
            case 4:
                displayList(list);
                break;
            case 0:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    // Free the memory allocated for the circular linked list before exiting
    freeList(list);

    return 0;
}
