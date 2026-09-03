#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

void delete(struct Node** head) {
    if (!*head) { printf("List Empty!\n"); return; }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Deleted head element.\n");
}

void display(struct Node* head) {
    if (!head) { printf("List Empty!\n"); return; }
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, val;

    while (1) {
        printf("\n1. Insert  2. Delete  3. Display  4. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1 || choice == 4) break;

        switch (choice) {
            case 1: 
                printf("Value: "); 
                scanf("%d", &val); 
                insert(&head, val); 
                break;
            case 2: delete(&head); break;
            case 3: display(head); break;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
