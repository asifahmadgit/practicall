#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the end of a list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to concatenate two linked lists
void concatenate(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }
    struct Node* temp = *head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
}

// Main function to demonstrate
int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Create first list: 1 -> 2 -> 3
    insertEnd(&head1, 1);
    insertEnd(&head1, 2);
    insertEnd(&head1, 3);

    // Create second list: 4 -> 5 -> 6
    insertEnd(&head2, 4);
    insertEnd(&head2, 5);
    insertEnd(&head2, 6);

    printf("First Linked List:\n");
    printList(head1);

    printf("Second Linked List:\n");
    printList(head2);

    // Concatenate
    concatenate(&head1, head2);

    printf("Concatenated Linked List:\n");
    printList(head1);

    return 0;
}
