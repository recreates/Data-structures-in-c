#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} str;

str *createnode(int data){
    str *newnode = (str *)malloc(sizeof(str));
    if(!newnode){
        printf("\nMemory Error\n");
        return NULL;
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

str *createlist(int n){
    str *head = NULL;
    str *current = NULL;
    for (int i = 1; i <= n;i++){
        int element;
        printf("Enter element %d: ", i);
        scanf("%d", &element);
        str *newnode = createnode(element);
        if (head == NULL){
            head = newnode;
            current = head;
            head->next = head; //- newnode next is pointing to head making it circular
        }
        else{
            current->next = newnode;
            current = newnode;
            current->next = head; //- current next is pointing to head making it circular
        }


    }
    return head;
}

void printlist(str *head){
    printf("\nThe circular linked list is\n");
    str *ptr = head;
    do{
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

int main(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    str *first = createlist(n);
    printlist(first);
    return 0;

    str *current = first;
    str *next;
    do{
        next = current->next;
        free(current);
        current = next;
    } while (current != first);
}