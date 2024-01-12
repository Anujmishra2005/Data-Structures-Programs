#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for an element in the linked list
int search(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1; // Initialize position

    while (temp != NULL) {
        if (temp->data == key) {
            return position; // Element found, return position
        }
        temp = temp->next;
        position++;
    }

    return -1; // Element not found
}

int main() {
    struct Node* head = NULL;

    int n, value;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    printf("Linked List: ");
    displayList(head);

    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    int position = search(head, key);

    if (position != -1) {
        printf("Element %d found at position %d.\n", key, position);
    } else {
        printf("Element %d not found in the linked list.\n", key);
    }

    return 0;
}
