#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }

    Node(int value, Node *nextNode)
    {
        data = value;
        next = nextNode;
    }
};

class Queue
{
private:
    Node *peekNode; // Points to the front of the queue
    int currentSize;

public:
    // Constructor
    Queue()
    {
        peekNode = nullptr;
        currentSize = 0;
    }

    // Enqueue an element onto the queueu
    void enqueue(int x)
    {
       // write your code here. Create a new node with the value x and enqueue it onto the queue
       // update the peekNode and currentSize
        // Node *temp = new Node(x, peekNode);
        // peekNode = temp;
        // currentSize++;
        Node *temp = new Node(x);
        Node *curr = peekNode;
        currentSize++;
        if(curr==nullptr){
            peekNode = temp;
            return;
        }
        while(curr->next!=nullptr){
            curr = curr->next;
        }
        curr->next = temp;
    }

    // Remove and return the peek element
    int dequeue()
    {
        // write your code here. Check if the queueu is empty and return -1 if it is.
        // dequeue the peek element and return it
        // update the peekNode and currentSize
        // delete the node that was dequeued
        // if(isEmpty()){
        //     return -1;
        // }
        // Node *curr = peekNode;
        // Node *prev = nullptr;
        // while(curr->next!=nullptr){
        //     prev = curr;
        //     curr = curr->next;
        // }
        // int x = curr->data;
        // if(curr==peekNode){
        //     peekNode = nullptr;
        // }
        // else{
        //     prev->next = nullptr;
        // }
        // delete curr;
        // currentSize--;
        // return x;
        if(isEmpty()){
            return -1;
        }
        Node *curr = peekNode;
        int x = curr->data;
        if(curr->next!=nullptr){
            peekNode = peekNode->next;
        }
        else{
            peekNode = nullptr;
        }
        delete curr;
        currentSize--;
        return x;
    }

    // Return the peek element without removing it
    int peek()
    {
        // write your code here. Check if the queueu is empty and return -1 if it is.
        // return the peek element
        if(isEmpty()){
            return -1;
        }
        Node *curr = peekNode;
        // while(curr->next!=nullptr){
        //     curr = curr->next;
        // }
        return curr->data;
    }

    // Return the number of elements in the queueu
    int length()
    {
        // write your code here. Return the number of elements in the queueu
        return currentSize;
    }

    // Check if the queueu is empty
    bool isEmpty()
    {
        // write your code here. Return true if the queueu is empty, false otherwise
        if(peekNode==nullptr){
            return true;
        }
        else{
            return false;
        }
    }

    // Clear the queueu
    void clear()
    {
        while (!isEmpty())
        {
            dequeue(); // Continuously dequeue elements until the queueu is empty
        }
    }

    // Destructor
    ~Queue()
    {
        clear();
    }
};
