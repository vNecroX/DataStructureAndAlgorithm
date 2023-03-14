#include <iostream>
#include <windows.h>

class Lifo{
    private:
        class Node{
            public:
                char data;
                Node *nextNode;
        };
        Node *rootNode;

    public:
        Lifo();
        ~Lifo();
        void push(char ch);
        char pop();
        void show();
};

Lifo::Lifo(){ rootNode = NULL; }

Lifo::~Lifo(){
    Node *recentNode = rootNode;
    Node *targetNode;

    while(recentNode != NULL){
        targetNode = recentNode;
        recentNode = recentNode->nextNode;
        delete targetNode;
    }
}

void Lifo::push(char ch){
    Node *newNode;
    
    newNode = new Node();
    newNode->data = ch;

    if(rootNode == NULL){
        rootNode = newNode;
        newNode->nextNode = NULL;
    }
    else{
        newNode->nextNode = rootNode;
        rootNode = newNode;
    }
}

char Lifo::pop(){
    if(rootNode != NULL){
        char data = rootNode->data;
        Node *targetNode = rootNode;

        rootNode = rootNode->nextNode;
        delete targetNode;

        return data;
    }
    else
        return '/';
}

void Lifo::show(){
    Node *recentNode = rootNode;

    if(recentNode != NULL){
        while(recentNode != NULL){
            std::cout<<recentNode->data<<"-";
            recentNode = recentNode->nextNode;
        }
    }
    else    
        std::cout<<"Lifo is empty!";
}

void menu();

using namespace std;

int main(){
    Lifo Lifo;

    int opt;
    char data;

    do{
        Sleep(2000);
        system("CLS");
        menu();
        cin>>opt;

        switch(opt){
            case 0:
                cin>>data;
                cout<<"Push("<<data<<")<-"<<endl;
                Lifo.push(data);
                break;

            case 1:
                cout<<"Pop() = "<<Lifo.pop()<<endl;
                break;

            case 2:
                Lifo.show();
                break;

            default : cout<<"See U later!"; break;
        }
    }while(opt == 0 || opt == 1 || opt == 2);

    return 0;
}

void menu(){
    cout<<"-  -  -  -  -  -"<<endl;
    cout<<"0: push new char"<<endl;
    cout<<"1: pop last char"<<endl;
    cout<<"2: show elements"<<endl;
    cout<<"-  -  -  -  -  -"<<endl;
}
