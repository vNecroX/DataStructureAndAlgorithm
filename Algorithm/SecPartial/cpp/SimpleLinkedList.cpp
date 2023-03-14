#include <iostream>
#include <windows.h>

class SimpleLinkedList{
    private:
        class Node{
            public:
                int data;
                Node *nextNode;
        };
        Node *headerNode;

    public:
        SimpleLinkedList();
        ~SimpleLinkedList();
        void push(int d);
        void pop(int d);
        void display();
        void searchNode(int d);
};

SimpleLinkedList::SimpleLinkedList(){ headerNode = NULL; }

SimpleLinkedList::~SimpleLinkedList(){
    Node *recentNode = headerNode;
    Node *targetNode;

    while(recentNode != NULL){
        targetNode = recentNode;
        recentNode = recentNode->nextNode;
        delete targetNode;
    }
}

void SimpleLinkedList::push(int d){
    Node *newNode = new Node();
    newNode->data = d;

    Node *aux1 = headerNode;
    Node *aux2;

    while((aux1 != NULL) && (aux1->data < d)){
        aux2 = aux1;
        aux1 = aux1->nextNode;
    }

    if(headerNode == aux1)
        headerNode = newNode;
    else
        aux2->nextNode = newNode;

    newNode->nextNode = aux1;
}

void SimpleLinkedList::pop(int d){
    if(headerNode != NULL){
        Node *targetNode = headerNode;
        Node *previousNode = NULL;

        while((targetNode != NULL) && (targetNode->data != d)){
            previousNode = targetNode;
            targetNode = targetNode->nextNode;
        }

        if(targetNode == NULL)
            std::cout<<"\nElement has not been found!";
        else if(previousNode == NULL){
            headerNode = headerNode->nextNode;
            std::cout<<"\nElement: "<<targetNode->data<<" has been deleted!";
            delete targetNode;
        }
        else{
            previousNode->nextNode = targetNode->nextNode;
            std::cout<<"\nElement: "<<targetNode->data<<" has been deleted!";
            delete targetNode;
        }
    }
}

void SimpleLinkedList::display(){
    Node *recentNode = headerNode;

    while(recentNode != NULL){
        std::cout<<recentNode->data<<"-";
        recentNode = recentNode->nextNode;
    }    
}

void SimpleLinkedList::searchNode(int d){
    Node *recentNode = headerNode;

    while(recentNode != NULL){
        std::cout<<recentNode->data<<"-";

        if(recentNode->data == d){
            d = -1;
            std::cout<<"\nElement: "<<recentNode->data<<" has been found!";
            break;
        }

        recentNode = recentNode->nextNode;
    } 

    if(d != -1)
        std::cout<<"\nElement has not been found!";
}

void menu();

using namespace std;

int main(){
    SimpleLinkedList SLL;

    int opt; int nodeData;

    do{
        Sleep(2000);
        system("CLS");
        menu();
        cin>>opt;

        switch(opt){
            case 0:
                cin>>nodeData;
                cout<<"Push("<<nodeData<<")<-"<<endl;
                SLL.push(nodeData);
                break;

            case 1:
                cout<<"Data to pop: ";
                cin>>nodeData;
                SLL.pop(nodeData);
                break;

            case 2:
                SLL.display();
                break;

            case 3:
                cout<<"Data to search: ";
                cin>>nodeData;
                SLL.searchNode(nodeData);
                break;

            default : cout<<"See U later!"; break;
        }
    }while(opt == 0 || opt == 1 || opt == 2 || opt == 3);

    return 0;
}

void menu(){
    cout<<"-  -  -  -  -  -"<<endl;
    cout<<"0: push new data"<<endl;
    cout<<"1: pop selected data"<<endl;
    cout<<"2: display elements"<<endl;
    cout<<"3: search element"<<endl;
    cout<<"-  -  -  -  -  -"<<endl;
}