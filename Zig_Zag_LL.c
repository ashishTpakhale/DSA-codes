#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the linked list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
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

// Function to find the middle of the linked list
struct Node* findMiddle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to fold the linked list and multiply overlapping nodes
void foldAndMultiply(struct Node** head, int k) {
    for (int i = 0; i < k; i++) {
        struct Node* mid = findMiddle(*head);
        struct Node* secondHalf = mid->next;
        mid->next = NULL;
        
        // Reverse the second half for zigzag fold
        secondHalf = reverseList(secondHalf);
        
        struct Node* firstHalf = *head;
        struct Node* temp1 = firstHalf;
        struct Node* temp2 = secondHalf;

        // Multiply the overlapping nodes
        while (temp1 != NULL && temp2 != NULL) {
            temp1->data *= temp2->data;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // Delete the second half nodes after fold
        while (secondHalf != NULL) {
            struct Node* temp = secondHalf;
            secondHalf = secondHalf->next;
            free(temp);
        }
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf("->");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    int n, k;
    char sequence[1000];

    // Input the number of nodes
    scanf("%d", &n);
    
    // Input the comma-separated integer sequence
    scanf("%s", sequence);
    
    // Input the number of K folds
    scanf("%d", &k);
    
    // Parse the sequence and append nodes
    char* token = strtok(sequence, ",");
    while (token != NULL) {
        appendNode(&head, atoi(token));
        token = strtok(NULL, ",");
    }
    
    // Perform K Zigzag folds
    foldAndMultiply(&head, k);

    // Print the resultant linked list
    printf("The resultant linked list is: ");
    printList(head);

    return 0;
}
