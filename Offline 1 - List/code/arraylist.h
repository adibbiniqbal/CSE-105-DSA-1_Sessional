#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int * array;
    // Add more fields here
    int capacity;
    int size;
    int position;    
} ArrayList;


void init_arraylist(ArrayList *list, int capacity)
{
    //printf("implement init_arraylist\n");
    // dynamically allocate space for the array
    // initialize the size, capacity, and current position
    list->capacity = capacity;
    list->array = (int*)malloc(capacity*sizeof(int));
    list->size = 0;
    list->position = 0;
}


void clear(ArrayList *list)
{
    //printf("Implement clear\n");
    // clear the list but do not free the array
    // modify the size, capacity, and current position
    printf("cleared list\n");
    list->size = 0;
    list->position = 0;
}

int get_size(ArrayList *list)
{
    //printf("Implement get_size\n");
    printf("size is %d\n", list->size);
    return list->size;
}


void resize(ArrayList *list, int new_capacity)
{
    //printf("Implement resize\n");
    // allocate space for new array with new_capacity
    // print log message
    printf("resized array from %d to %d\n", list->capacity, new_capacity);
    list->capacity = new_capacity;
    int *temp = (int*)malloc(list->capacity*sizeof(int));
    for(int i=0; i<list->size; i++){
        temp[i] = list->array[i];
    }
    free(list->array);
    list->array = temp;
}


void append(ArrayList *list, int value)
{
    //printf("Implement append\n");
    // call resize if necessary
    // add value to the end of the list
    if(list->size>=list->capacity){
        resize(list, 2*list->capacity);
    }
    list->array[list->size++] = value;
    printf("appended %d\n", value);
}


void insert(ArrayList *list, int value)
{
    //printf("Implement insert\n");
    // call resize if necessary
    // shift the elements to the right to make space
    // add value at the current position
    if(list->size>=list->capacity){
        resize(list, 2*list->capacity);
    }
    for(int i = list->size; i>= list->position; i--){
        list->array[i] = list->array[i-1];
    }
    list->array[list->position] = value;
    printf("inserted %d\n", value);
    list->size++;
}


int remove_at_current(ArrayList *list)
{
    //printf("Implement remove_at_current\n");
    //return -1;
    // save the value of the current element in a variable
    // shift the elements to the left to fill the gap
    // change the size, and current position as necessary
    // call resize if necessary
    // return the saved value
    int temp = list->array[list->position];
    for(int i=list->position;i<list->size-1;i++){
        list->array[i]=list->array[i+1];
    }
    list->size--;
    if(list->size<(list->capacity/4)){
        resize(list, list->capacity/2);
    }
    printf("removed %d\n", temp);
    return temp;
}

int find(ArrayList *list, int value)
{
    // printf("Implement find\n");
    // return -1;
    // traverse the list and return the position of the value
    // return -1 if the value is not found
    int idx = -1;
    for(int i=0 ;i<list->size; i++){
        if(list->array[i]==value){
            idx = i;
        }
    }
    if(idx==-1){
        printf("did not find %d in the list\n", value);
    }
    else{
        printf("found %d at %d\n", value, idx);
    }
    return idx;
}


void move_to_start(ArrayList *list)
{
    //printf("Implement move_to_start\n");
    // consider the cases when the list is empty
    if(list->size==0){
        printf("list is empty");
        return;
    }
    printf("moved to position 0\n");
    list->position = 0;
}


void move_to_end(ArrayList *list)
{
    //printf("Implement move_to_end\n");
    // consider the cases when the list is empty
    if(list->size==0){
        printf("list is empty");
        return;
    }
    printf("moved to position %d\n", list->size-1);
    list->position = list->size-1;
}


void prev(ArrayList *list)
{
    //printf("Implement prev\n");
    // no change if the current position is at the start
    if(list->position != 0){
        printf("moved current position from %d to %d\n", list->position, list->position-1);
        list->position--;
    }
    else{
        printf("already at start position\n");
    }
}


void next(ArrayList *list)
{
    //printf("Implement next\n");
    // no change if the current position is at the end
    if(list->position != list->size-1){
        printf("moved current position from %d to %d\n", list->position, list->position+1);
        list->position++;
    }
    else{
        printf("already at end position\n");
    }
}


void move_to_position(ArrayList *list, int position)
{
    //printf("Implement move_to_position\n");
    printf("moved current position from %d to %d\n", list->position, position);
    list->position = position;
}


int get_current_position(ArrayList *list)
{
    // printf("Implement get_current_position\n");
    // return -1;
    printf("current position is %d\n", list->position);
    return list->position;
}


int get_current_element(ArrayList *list)
{
    // printf("Implement get_current_element\n");
    // return -1;
    printf("current element is %d\n", list->array[list->position]);
    return list->array[list->position];
}


void print_list(ArrayList *list)
{
    //printf("< list elements here >");
    printf("< ");
    for(int i=0;i<list->size;i++){
        if(i==list->position){
            printf("|");
        }
        printf("%d ", list->array[i]);
    }
    printf(">\n");
}


void free_list(ArrayList *list)
{
    //printf("Implement free_list\n");
    // free the array before terminating the program
    free(list->array);
}


