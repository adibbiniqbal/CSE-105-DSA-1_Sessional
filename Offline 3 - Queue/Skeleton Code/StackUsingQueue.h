#include "QueueLinkedList.h"
#include <iostream>
using namespace std;

class Stack
{
private:
    
    //write your code here. Add additional private variables if necessary
    Queue q;
    int size;

public:
    // Constructor
    Stack()
    {
        //write your code here. Initialize additional private variables if necessary
        size = 0;
    }
    Stack(int initialCapacity)
    {
        //write your code here. Initialize additional private variables if necessary
    }

    // Destructor
    ~Stack()
    {
    }

    
    // Push an element onto the stack
    void push(int x)
    {
        //write your code here.
        //push the element onto the stack
        q.enqueue(x);
        size++;
    }

    // Remove and return the top element
    int pop()
    {
       //write your code here. Check if the stack is empty and return -1 if it is.
       //pop the top element and return it
        if(q.isEmpty()){
            return -1;
        }
        Queue temp;
        while(q.length()>1){
            temp.enqueue(q.dequeue());
        }
        int x = q.dequeue();
        while(!temp.isEmpty()){
            q.enqueue(temp.dequeue());
        }
        size--;
        return x;
    }

    // Return the top element without removing it
    int top()
    {
        //write your code here. Check if the stack is empty and return -1 if it is.
        //return the top element
        if(q.isEmpty()){
            return -1;
        }
        Queue temp;
        int x;
        while(!q.isEmpty()){
            x = q.dequeue();
            temp.enqueue(x);
        }
        while(!temp.isEmpty()){
            q.enqueue(temp.dequeue());
        }
        return x;
    }

    // Return the number of elements in the stack
    int length()
    {
        //write your code here. Return the number of elements in the stack
        return size;
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        //write your code here. Return true if the stack is empty, false otherwise
        if(size==0){
            return true;
        }
        else{
            return false;
        }
    }

    // Clear the stack
    void clear()
    {
        //write your code here. Clear the stack.
        q.clear();
    }
};
