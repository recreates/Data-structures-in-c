#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} src;

src *createnode(int data) {
    src *newnode = (src *)malloc(sizeof(src));
    if (!newnode) {
        printf("\nMemory Error\n");
        exit(EXIT_FAILURE);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

src *createlist(int n) {
    src *head = NULL; //- points to the first node
    src *current = NULL; //- used to traverse the list

    for (int i = 1; i <= n; i++) {
        int element;
        printf("\nEnter element %d: ", i);
        scanf("%d", &element);

        src *newnode = createnode(element);

        if (head == NULL) {
            
            head = newnode;
            current = head;
        } else {
            
            current->next = newnode;
            current = newnode;
        }
    }

    return head;
}

void printlist(src *head) {
    printf("\nThe given list is\n");
    src *ptr = head;
    while (ptr != NULL) {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    int n;
    printf("Enter the number of nodes you want in your program: ");
    scanf("%d", &n);
    src *first = createlist(n);
    printlist(first);

    src *current = first;
    src *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
