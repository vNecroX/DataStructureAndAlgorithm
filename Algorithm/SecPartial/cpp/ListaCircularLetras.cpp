#include <iostream>

class CycleLetterList{
    private:
        class Node{
            public:
                char data;
                Node *nextNode;

                Node(){};
                Node(char d, Node *p=NULL) : data(d), nextNode(p){}
                ~Node(){}
        };
        Node *head;
        Node *rear;

    public:
        CycleLetterList();
        ~CycleLetterList();
        void appendHead(char d);
		void printList();
};

CycleLetterList::CycleLetterList(){
    head = new Node();
    head->nextNode = head;
    head->data = 0;
    rear = NULL; 
}

CycleLetterList::~CycleLetterList(){
    if(head){
        Node *p = head->nextNode;

        while(p != rear){
            head->nextNode = p->nextNode;
			delete p;
			p = head->nextNode;
        }

        delete head;
		head = NULL;
		delete rear;
		rear = NULL;
    }
}

void CycleLetterList::appendHead(char d){
	if(head == head->nextNode){
		Node *node = new Node(d); 
		head->nextNode = node;
		node->nextNode = head;
		rear = node;
	}else{
		Node *node = new Node(d, head->nextNode);
		rear->nextNode = node;
		head->nextNode = node;
	}
}

void CycleLetterList::printList(){
	std::cout<<"\nDatos capturados: ";
	if(head != head->nextNode){
		Node *p = head->nextNode;

		while(p){
			std::cout <<p->data<<"-"; 
			p = p->nextNode;

			if(p == head->nextNode)
			    break;
		}
	}
	std::cout<<"\n";
}

using namespace std;

int main(){
    CycleLetterList CLL;

	int hmLetters; int i = 0;
	char data;

	cout<<"Cantidad de letras a introducir: ";
	cin>>hmLetters;
	cout<<"\nInserte esa cantidad de letras:\n";

	for (; i<hmLetters; i++){
		cin>>data;
		CLL.appendHead(data);
	}
	CLL.printList();

    return 0;
}
