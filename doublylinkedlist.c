#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *prev; //- new field added which is called previous field
    struct node *next;
} str;

str *createnode(int data){
    str *newnode = (str *)malloc(sizeof(str));
    if(!newnode){
        printf("\nMemory Error\n");
        return NULL;
    }
    newnode->data = data;
    newnode->prev = NULL; //- previous field is pointed to NULL at first just like next field
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

        if(head==NULL){
            head = newnode;
            current = head;
        }
        else{
            current->next = newnode; //- newnode is the next node of current
            newnode->prev = current;  //- pointing the prev of newnode to current since current is behind newnode at this point
            current = newnode; //- current moves to newnode here
        }
    }
    return head;
}

void printlist(str *head){
    printf("\nThe list is\n");
    str *ptr = head;
    while(ptr!= NULL){
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
}
int main(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    str *first = createlist(n);
    printlist(first);

    //- free memory

    str *current = first;
    str *next;
    while(current!=NULL){
        next = current->next;
        free(current);
        current = next;
    }
    return 0;
}