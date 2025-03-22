#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    // add *next and *prev here
    struct Node *next;
    struct Node *prev;
} Node;


typedef struct
{
    // add Node* head, tail, current_position and other necessary fields here
    Node *head;
    Node *tail;
    Node *position;
    
} LinkedList;


void init_linkedlist(LinkedList *list)
{
    //printf("implement init_linkedlist\n");
    // initialize head, tail with null
    list->head = NULL;
    list->tail = NULL;
    list->position = NULL;
}


void clear(LinkedList *list)
{
    //printf("Implement clear\n");
    // traverse the list and free each node
    // set head and tail to null
    Node *curr=list->head;
    Node *prev=NULL;
    while(curr!=NULL){
        prev=curr;
        curr=curr->next;
        free(prev);
    }
    list->head = NULL;
    list->tail = NULL;
    printf("cleared list\n");
}


int get_size(LinkedList *list)
{
    // printf("Implement get_size\n");
    // return -1;
    if(list->head==NULL){
        printf("size is 0\n");
        return 0;
    }
    int count = 0;
    Node *temp = list->head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    printf("size is %d\n", count);
    return count;
}


void append(LinkedList *list, int value)
{
    //printf("Implement append\n");
    // create a new node and set its value
    // consider the case when the list is empty and when it isnt
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    if(list->head==NULL){
        list->head = new_node;
        list->tail = new_node;
    }
    else{
        new_node->prev = list->tail;
        new_node->next = list->tail->next;
        list->tail->next = new_node;
        list->tail = new_node;
    }
    if(list->position==NULL){
        list->position = list->head;
    }
    printf("appended %d\n", value);
}


void insert(LinkedList *list, int value)
{
    //printf("Implement insert\n");
    // create a new node and set its value
    // place it at the current position (check order of operations)
    // consider the case when the list is empty and when it isnt
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    if(list->head==NULL){
        list->head = new_node;
        list->tail = new_node;
        list->position = new_node;
    }
    else if(list->position==list->head){
        list->position = new_node;
        new_node->next = list->head;
        new_node->prev = NULL;
        list->head->prev = new_node;
        list->head = new_node;
    }
    else{
        list->position->prev->next=new_node;
        new_node->prev = list->position->prev;
        new_node->next = list->position;
        list->position->prev = new_node;
        list->position = new_node;
    }
    printf("inserted %d\n", value);
}


int remove_at_current(LinkedList *list)
{
    //printf("Implement remove_at_current\n");
    // consider the case when current code is at the begining or at the end
    //return -1;
    if(list->position==NULL){
        printf("invalid position");
        return -1;
    }
    int value;
    Node *temp;
    if(list->position==list->head){
        value = list->head->data;
        temp = list->head;
        list->position = list->head->next;
        list->head = list->head->next;
        list->head->prev = NULL;
        free(temp);
    }
    else if(list->position==list->tail){
        value = list->tail->data;
        temp = list->tail;
        list->position = list->tail->prev;
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        free(temp);
    }
    else{
        value = list->position->data;
        temp = list->position;
        list->position->prev->next = list->position->next;
        list->position->next->prev = list->position->prev;
        list->position = list->position->next;
        free(temp);
    }
    printf("removed %d\n", value);
    return value;
}


int find(LinkedList *list, int value)
{
    //printf("Implement find\n");
    // traverse the list and return the position of the value
    //return -1;
    Node *temp = list->head;
    int pos = 0;
    while(temp!=NULL){
        if(temp->data==value){
            printf("found %d at %d\n", value, pos);
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    printf("did not find %d in the list\n", value);
    return -1;
}


void move_to_start(LinkedList *list)
{
    //printf("Implement move_to_start\n");
    printf("moved to start\n");
    list->position = list->head;
}


void move_to_end(LinkedList *list)
{
    //printf("Implement move_to_end\n");
    printf("moved to end\n");
    list->position=list->tail;
}


void prev(LinkedList *list)
{
    //printf("Implement prev\n");
    if(list->position != list->head){
        list->position = list->position->prev;
        printf("decremented position by 1\n");
    }
    else{
        printf("already at start\n");
    }
}


void next(LinkedList *list)
{
    //printf("Implement next\n");
    if(list->position != list->tail){
        list->position = list->position->next;
        printf("incremented position by 1\n");
    }
    else{
        printf("already at end\n");
    }
}


void move_to_position(LinkedList *list, int position)
{
    //printf("Implement move_to_position\n");
    // traverse the list and stop at the given position
    Node *temp = list->head;
    int i = 0;
    while(temp!=NULL && i<position){
        temp = temp->next;
        i++;
    }
    list->position = temp;
    printf("moved to position %d\n", position);
    // if(i==position){
    //     list->position = temp;
    //     printf("moved to position %d\n", position);
    // }
    // else{
    //     printf("invalid position\n");
    // }
}


int get_current_position(LinkedList *list)
{
    //printf("Implement get_current_position\n");
    // traverse the list and stop when you are at the current position
    // return the position (integer)
    //return -1;
    Node *temp = list->head;
    int i = 0;
    while(temp!=list->position && temp!=NULL){
        temp = temp->next;
        i++;
    }
    printf("current position is %d\n", i);
    return i;
}


int get_current_element(LinkedList *list)
{
    //printf("Implement get_current_element\n");
    // return the value at the current position
    //return -1;
    if(list->position!=NULL){
        printf("current element is %d\n", list->position->data);
        return list->position->data;
    }
    else{
        printf("invalid position\n");
        return -1;
    }
}


void print_list(LinkedList *list)
{
    //printf("< list elements here >");
    Node *temp = list->head;
    printf("< ");
    while(temp!=NULL){
        if(temp==list->position){
            printf("|");
        }
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf(">\n");
}


void free_list(LinkedList *list)
{
    //printf("Implement free_list\n");
    // free each node in the list
    Node *curr=list->head;
    Node *prev=NULL;;
    while(curr!=NULL){
        prev=curr;
        curr=curr->next;
        free(prev);
    }
    list->head = NULL;
    list->tail = NULL;
    //printf("freed list\n");
}
