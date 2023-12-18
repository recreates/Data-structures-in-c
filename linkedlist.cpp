#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} src;

src *createlist(int data) {
    src *newnode = (src *)malloc(sizeof(src));
    if (!newnode) {
        printf("\nMemory Error\n");
        return NULL;
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void printlist(src *head) {
    src *ptr = head;
    while (ptr != NULL) {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    int n, firstelement, nextelement;
    src *head = NULL;  

    printf("Enter the number of nodes you want for the linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            printf("\nEnter the first element: ");
            scanf("%d", &firstelement);
            head = createlist(firstelement)   ;
        } else {
            printf("\nEnter the next element: ");
            scanf("%d", &nextelement);
         
            src *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = createlist(nextelement);
        }
    }

    printlist(head);

    return 0;
}
