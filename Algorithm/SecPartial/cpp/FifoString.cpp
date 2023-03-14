#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Fifo{
    private:
        class Node{
            public:
                string data;
                Node *nextNode;
        };
        Node *rootNode;
        Node *lastNode;

    public:
        Fifo();
        ~Fifo();
        void push(string st);
        string pop();
        void show();
};

Fifo::Fifo(){ rootNode = NULL; }

Fifo::~Fifo(){
    Node *recentNode = rootNode;
    Node *targetNode;

    while(recentNode != NULL){
        targetNode = recentNode;
        recentNode = recentNode->nextNode;
        delete targetNode;
    }
}

void Fifo::push(string st){
    Node *newNode;

    newNode = new Node();
    newNode->data = st;

    if(rootNode == NULL)
        rootNode = newNode;
    else
        lastNode->nextNode = newNode;
    
    lastNode = newNode;
}

string Fifo::pop(){
    if(rootNode != NULL){
        string data = rootNode->data;
        Node *targetNode = rootNode;

        rootNode = rootNode->nextNode;
        delete targetNode;

        return data;
    }
    else
        return "/";
}

void Fifo::show(){
    Node *recentNode = rootNode;

    if(recentNode != NULL){
        while(recentNode != NULL){
            std::cout<<recentNode->data<<"-";
            recentNode = recentNode->nextNode;
        }
    }
    else
        std::cout<<"Fifo is empty!";
}

void menu();

int main(){
    Fifo Fifo;

    int opt;
    string data;

    do{
        Sleep(2000);
        system("CLS");
        menu();
        cin>>opt;

        switch(opt){
            case 0:
                cin.ignore();
                getline(cin, data);
                cout<<"Push("<<data<<")<-"<<endl;
                Fifo.push(data);
                break;

            case 1:
                cout<<"Pop() = "<<Fifo.pop()<<endl;
                break;

            case 2:
                Fifo.show();
                break;

            default : cout<<"See U later!"; break;
        }
    }while(opt == 0 || opt == 1 || opt == 2);

    return 0;
}

void menu(){
    cout<<"-  -  -  -  -  -"<<endl;
    cout<<"0: push new string"<<endl;
    cout<<"1: pop first string"<<endl;
    cout<<"2: show elements"<<endl;
    cout<<"-  -  -  -  -  -"<<endl;
}
