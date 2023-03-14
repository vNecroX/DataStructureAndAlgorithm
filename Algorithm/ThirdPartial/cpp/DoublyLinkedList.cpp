#include <iostream>

class Node{
    public:
        int data;
        Node *prevNode;
        Node *nextNode;
};

void push(Node **_head, int d){
    Node *newNode = new Node();
    newNode->data = d;
    newNode->nextNode = (*_head);
    newNode->prevNode = NULL;

    if((*_head) != NULL)
        (*_head)->prevNode = newNode;
    
    (*_head) = newNode;
}

void pop(Node **_head, Node *targetNode){
    if(*_head == NULL || targetNode == NULL)
        return;

    if(*_head == targetNode)
        *_head = targetNode->nextNode;

    if(targetNode->nextNode != NULL)
        targetNode->nextNode->prevNode = targetNode->prevNode;

    if(targetNode->prevNode != NULL)
        targetNode->prevNode->nextNode = targetNode->nextNode;

    delete targetNode;
    return;
}

void pushBeforeNode(Node **_head, Node *_nextNode, int d){
    if(_nextNode == NULL){
        std::cout<<"\nGiven next node cannot be NULL!";
        return;
    }

    Node *newNode;
    newNode->data = d;
    newNode->prevNode = _nextNode->prevNode;
    _nextNode->prevNode = newNode;
    newNode->nextNode = _nextNode;

    if(newNode->prevNode != NULL)
        newNode->prevNode->nextNode = newNode;
    else    
        *_head = newNode;
}

void pushAfterNode(Node *_prevNode, int d){
    if(_prevNode == NULL){
        std::cout<<"\nGiven previous node cannot be NULL!";
        return;
    }

    Node *newNode = new Node();
    newNode->data = d;
    newNode->nextNode = _prevNode->nextNode;
    _prevNode->nextNode = newNode;
    newNode->prevNode = _prevNode;

    if(newNode->nextNode != NULL)
        newNode->nextNode->prevNode = newNode;
}

void append(Node **_head, int d){
    Node *newNode = new Node();
    Node *lastNode = *_head;

    newNode->data = d;
    newNode->nextNode = NULL;

    if(*_head == NULL){
        newNode->prevNode = NULL;
        *_head = newNode;
        return;
    }

    while(lastNode->nextNode != NULL)
        lastNode = lastNode->nextNode;

    lastNode->nextNode = newNode;
    newNode->prevNode = lastNode;
}

void printList(Node *_node){
    Node *lastNode;

    std::cout<<"\nIn forward direction: ";
    while(_node != NULL){
        std::cout<<" "<<_node->data<<" ";
        lastNode = _node;
        _node = _node->nextNode;
    }

    std::cout<<"\nIn reverse direction: ";
    while(lastNode != NULL){
        std::cout<<" "<<lastNode->data<<" ";
        lastNode = lastNode->prevNode;
    }
}

using namespace std;

int main(){
    Node *head = NULL;
    
    append(&head, 16);
    push(&head, 4);
    push(&head, 2);
    printList(head);

    cout<<"\n\nInserted new node after head. . .";
    pushAfterNode(head->nextNode, 8);
    printList(head);

    cout<<"\n\nInserted new node before head. . .";
    pushAfterNode(head->prevNode, 32);
    printList(head);

    cout<<"\n\nDeleted new node after head. . .";
    pop(&head, head->nextNode);
    printList(head);

    cout<<"\n\nDeleted new node head. . .";
    pop(&head, head);
    printList(head);

    return 0;
}
