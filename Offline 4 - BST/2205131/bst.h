#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
};

Node *insertNode(Node *node, int val)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST and 
    // the value to be inserted
    // Returns the pointer to the root of the modified BST.
    if(!node)
    {
        node = new Node;
        node->val = val;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }
    Node *root = node;
    Node *parent = nullptr;
    while(node)
    {
        parent = node;
        if(val<node->val)
            node = node->left;
        else if(val>node->val)
            node = node->right;
        else
            return root;
    }
    Node *temp = new Node;
    temp->val = val;
    temp->left = nullptr;
    temp->right = nullptr;
    if(val<parent->val)
        parent->left = temp;
    else
        parent->right = temp;
    return root;

}

Node *deleteNode(Node *node, int val)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST and 
    // the value to be deleted.
    // Returns the pointer to the root of the modified BST.
    if(!node)
        return nullptr;
    Node *root = node;
    Node *parent = nullptr;
    while(val!=node->val && node)
    {
        parent = node;
        if(val<node->val)
            node = node->left;
        else
            node = node->right;
    }
    if(!node)
        return root;
    if(!node->left && !node->right)
    {
        if(node==root)
            root = nullptr;
        else if(parent->left==node)
            parent->left=nullptr;
        else
            parent->right = nullptr;
        delete node;
    }
    else if(!node->left)
    {
        if(node==root)
            root = node->right;
        else if(parent->left==node)
            parent->left = node->right;
        else
            parent->right = node->right;
        delete node;
    }
    else if(!node->right)
    {
        if(node==root)
            root = node->left;
        else if(parent->left==node)
            parent->left = node->left;
        else
            parent->right = node->left;
        delete node;
    }
    else
    {
        Node *rightMin = node->right;
        Node *rightMinParent = node;
        while(rightMin->left)
        {
            rightMinParent = rightMin;
            rightMin = rightMin->left;
        }
        node->val = rightMin->val;
        if(rightMin->right)
            rightMinParent->left = rightMin->right;
        else
            rightMinParent->left = nullptr;
        delete rightMin;
    }
    return root;
}

Node* find(Node *node, int val)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST and 
    // the value to be searched.
    // Returns the pointer to the node that contains val.
    // Returns NULL if not found.
    Node *temp = node;
    while(temp)
    {
        if(val==temp->val)
            return temp;
        else if(val<temp->val)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return nullptr;
}

void inOrder(Node *node)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST
    // Prints the in-order traversal of the given BST
    if(node)
    {
        inOrder(node->left);
        cout << node->val <<" ";
        inOrder(node->right);
    }
}

void preOrder(Node *node)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST
    // Prints the pre-order traversal of the given BST
    if(node)
    {
        cout << node->val << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void postOrder(Node *node)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST
    // Prints the post-order traversal of the given BST
    if(node)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->val << " ";
    }
}

void printTree(Node *root){
    // Write your codes here
    // This function takes a pointer to the root of the BST
    // Prints parenthesized representation of the given BST
    if(!root)
    {
        cout << "_";
        return;
    }
    cout << root->val ;
    if(root->left || root->right)
    {
        cout << " (";
        if(root->left)
            printTree(root->left);
        else   
            cout << "_ ";
        cout << ", ";
        if(root->right)
            printTree(root->right);
        else   
            cout << " _";
        cout << ") ";
    }
}