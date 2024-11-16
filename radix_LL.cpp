#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(struct node** head, int data) {
    struct node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int findMax(struct node* head) {
    int max = head->data;
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

int getDigit(int number, int place) {
    return (number / place) % 10;
}

void radixSort(struct node** head) {
    int max = findMax(*head);
    int place = 1;

    struct node* buckets[10];
    for (int i = 0; i < 10; i++) {
        buckets[i] = NULL;
    }

    while (max / place > 0) {
        struct node* temp = *head;

        while (temp != NULL) {
            int digit = getDigit(temp->data, place);
            appendNode(&buckets[digit], temp->data);
            temp = temp->next;
        }

        struct node* newHead = NULL;
        struct node* tail = NULL;
        for (int i = 0; i < 10; i++) {
            if (buckets[i] != NULL) {
                if (newHead == NULL) {
                    newHead = buckets[i];
                    tail = buckets[i];
                } else {
                    tail->next = buckets[i];
                }
                while (tail->next != NULL) {
                    tail = tail->next;
                }
            }
            buckets[i] = NULL;
        }

        *head = newHead;
        place *= 10;
    }
}

void printList(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {

    struct node* list = NULL;

    appendNode(&list, 170);
    appendNode(&list, 45);
    appendNode(&list, 75);
    appendNode(&list, 90);
    appendNode(&list, 802);
    appendNode(&list, 24);
    appendNode(&list, 2);
    appendNode(&list, 66);

    radixSort(&list);

    printf("The Sorted list: ");
    printList(list);

    return 0;
}
