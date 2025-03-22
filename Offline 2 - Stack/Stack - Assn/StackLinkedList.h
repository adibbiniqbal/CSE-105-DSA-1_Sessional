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

class Stack
{
private:
    Node *topNode; // Points to the top of the stack
    int currentSize;

public:
    // Constructor
    Stack()
    {
        topNode = nullptr;
        currentSize = 0;
    }

    // Push an element onto the stack
    void push(int x)
    {
       //write your code here. Create a new node with the value x and push it onto the stack
       //update the topNode and currentSize
        Node *temp = new Node(x, topNode);
        topNode = temp;
        currentSize++;
    }

    // Remove and return the top element
    int pop()
    {
        //write your code here. Check if the stack is empty and return -1 if it is.
        //pop the top element and return it
        //update the topNode and currentSize
        //delete the node that was popped
        if(topNode==nullptr){
            return -1;
        }
        int x = topNode->data;
        Node *temp = topNode->next;
        topNode->next = nullptr;
        delete topNode;
        topNode = temp;
        currentSize--;
        return x;
    }

    // Return the top element without removing it
    int top()
    {
        //write your code here. Check if the stack is empty and return -1 if it is.
        //return the top element
        if(topNode==nullptr){
            return -1;
        }
        else{
            return topNode->data;
        }
    }

    // Return the number of elements in the stack
    int length()
    {
        //write your code here. Return the number of elements in the stack
        return currentSize;
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        //write your code here. Return true if the stack is empty, false otherwise
        if(topNode==nullptr){
            return true;
        }
        else{
            return false;
        }
    }

    // Clear the stack
    void clear()
    {
        while (!isEmpty())
        {
            pop(); // Continuously pop elements until the stack is empty
        }
    }

    // Destructor
    ~Stack()
    {
        while (!isEmpty())
        {
            pop(); // Continuously pop elements until the stack is empty
        }
    }
};
