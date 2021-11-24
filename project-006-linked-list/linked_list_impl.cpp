#include <iostream>
#include <stdio.h>
#include <stdlib.h>


typedef struct node_t {
    int data;
    node_t* next ;
} node_t;

void push (node_t* head, int val){
    node_t* new_node = (node_t* ) malloc(sizeof(node_t));
    node_t* last = head;
    // find last node in the linked list
    while(last->next != NULL){
        last = last->next;
    }
    // allocate memory for the new stuff
    new_node->data = val;
    last->next = new_node;
    last->next->next = NULL;

}
int pop(node_t** headRef)
{
    // underflow condition
    if (*headRef == NULL) {
        return -1;
    }
 
    node_t* head = *headRef;
    int result = head->data;        // pull out data before the node is deleted
 
    (*headRef) = (*headRef)->next;  
    free(head);             // free the head node
 
    return result;          // don't forget to return the data from the link
}
     

void remove_last(node_t* head){
    node_t* last = head;
    
    while (last->next->next != NULL){
        last = last->next;
    }
    free(last->next);
    last->next = NULL;
}

void print_linked_list(node_t* head){
    int c = 0;
    node_t* current = head;
    while (current != NULL)
    {
        std::cout << "element[" << c <<"]" << " =" <<  current->data << std::endl;
        current = current->next;
        
        c++;
    }
    
}
int create_head(node_t** head){
    node_t* myhead = (node_t*) malloc(sizeof(node_t));
    if (myhead ==  NULL){
        std::cout << "couldn't allocate mem";
        return -1;
    }
    myhead->data = 0;
    myhead->next = NULL;
    *head =  myhead;
    return 0;
}
int main()
{
node_t* head = NULL;
create_head(&head);

if (head == NULL){
    printf("unable to allocatet mem for head");
}
push(head, 1);
push(head, 2);
push(head, 3);
remove_last(head);
pop(&head);
pop


print_linked_list(head);
// now head is alloated, try to push new member

return 0;
}