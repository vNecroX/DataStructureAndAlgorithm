#include <iostream>
#include <windows.h>

int i;

class CycleLinkedList{
    private:
        class Node{
            public:
                int data;
                Node *nextNode;

                Node(){};
                Node(int d, Node *p=NULL) : data(d), nextNode(p){}
                ~Node(){}
        };
        Node *head;
        Node *rear;
        int listLength;

    public:
        CycleLinkedList();
        ~CycleLinkedList();
        bool isEmpty();
        void appendHead(int d);
        void appendRear(int d);
        void insertNode(int pos, int d);
        void removeNode(int pos);
        int getNodePos(int d);
        void clearList();
        void printList();
        int getListLenght(){ return listLength; }
};

CycleLinkedList::CycleLinkedList() : listLength(0){
    head = new Node();
    head->nextNode = head;
    head->data = 0;
    rear = NULL; 
}

CycleLinkedList::~CycleLinkedList(){
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

bool CycleLinkedList::isEmpty(){
	if(listLength>0)
		return false;

	return true;
}

void CycleLinkedList::appendHead(int d){
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
	listLength++;
}

void CycleLinkedList::appendRear(int d){
	if(head == head->nextNode){
		Node *node = new Node(d);
		head->nextNode = node;
		rear = node; 
	}else{
		Node *node = new Node(d, head->nextNode);
		rear->nextNode = node;
		rear = node;
		node->nextNode = head->nextNode;
	}
	listLength++;
}

void CycleLinkedList::insertNode(int pos, int d){
	if(pos<0 || pos>listLength)
		return;

	if(pos == 0){// Insertar en el nodo principal 
		
        head->nextNode = new Node(d, head->nextNode); // Crea un nuevo nodo 
		
        if(listLength == 0)
			rear = head->nextNode;
		
		rear->nextNode = head->nextNode; // apunte el nodo final al nodo principal 
	}else if(pos == listLength){// Insertar al final 
		Node *node = new Node(d);
		if(listLength == 0){
			head->nextNode = node;
			node->nextNode = node;
			rear = node;
		}else{
			rear->nextNode = node;
			rear = node;
			node->nextNode = head->nextNode;
		}
	}else{// Inserta un elemento en el medio 
		Node *node = head->nextNode;

		for(i=0; i<pos-1; i++)// Encuentra el nodo anterior de la posición de inserción 
		    node = node->nextNode;
		
		Node *newNode = new Node(d, node->nextNode); // Apunte el nuevo nodo a la siguiente posición 
		node->nextNode = newNode; // El nodo anterior apunta al nuevo nodo 
	}
	listLength++;
}

void CycleLinkedList::removeNode(int pos){
	if(pos<0 || pos>= listLength || head==head->nextNode) // Determinar si se excede la longitud de la lista enlazada 
	    return;

	Node *node = head->nextNode;

	if(listLength == 1){// Juzgar si solo hay un nodo y eliminar el nodo actual 
		delete node;
		node = NULL;
		head->nextNode = head;
		rear = NULL;
	}else{
		if(pos == 0){// Determine la posición de la entrada 
		    Node *p = head->nextNode->nextNode; // Señala p a la siguiente posición que debe eliminarse 
			head->nextNode = p;
			rear->nextNode = p;
			delete node;
			node=NULL;
		}else if(pos == listLength-1) {// Elimina el último elemento 
			for(i = 0; i<pos-1; i++)// Encuentra el último elemento 
			    node = node->nextNode;
			
			delete rear; // Elimina el elemento tail y pon 
			rear = node;
			node->nextNode = head->nextNode;
		}else{
			for(i=0; i<pos-1; i++)
			    node=node->nextNode;
			
			Node *temp = node->nextNode;
			node->nextNode = temp->nextNode;
			delete temp;
			temp = NULL;
		}
	}
	listLength--;
}

int CycleLinkedList::getNodePos(int d){
	if(head == head->nextNode)
		return -1;
	
	Node *node = head->nextNode;
	for(i = 0; node!=rear && i<listLength; i++, node=node->nextNode){// Encuentra la posición del mismo elemento 
		if(d == node->data)
			return i;
	} 

	if(rear->data == d)
		return listLength-1;
	
	return -1;
}

void CycleLinkedList::clearList(){  
	Node *node = head->nextNode; // Definir el encabezado 
	while(node != rear){  
		head->nextNode = node->nextNode; // Cambia la posición del puntero para que apunte al siguiente nodo 
		delete node;
		node = head-> nextNode; // Definir el primer nodo como nodo 
	}
	 
    head->nextNode = NULL; // Establecer el encabezado en NULL 
	delete rear;
	rear = NULL;
	listLength = 0;
}
 // Recorre la lista vinculada 
void CycleLinkedList::printList(){
	std::cout<<"PrintList: \n";
	if(head != head->nextNode) {// ¿Está vacía la lista enlazada? 
		Node *p = head->nextNode;

		while(p){
			std::cout <<p->data<< ""; // Ingrese el valor actual, yp retrocede uno 
			p = p->nextNode;

			if(p == head-> nextNode)// Comprueba si p ha sido atravesado 
			    break;
		}
	}
	std::cout<<"\n";
}

using namespace std;

int main(){
    CycleLinkedList CLL;
	for (int i = 0; i < 7; ++i)
	{
		CLL.appendHead(i);
		CLL.appendRear(i);
	}
	CLL.printList();

    cout << "GetElemPos(6): " << CLL.getNodePos(6) << endl;
	cout << "GetElemPos(5): " << CLL.getNodePos(5) << endl;
	cout << "GetElemPos(0): " << CLL.getNodePos(0) << endl;
 
	CLL.removeNode(0);
	CLL.printList();
	CLL.removeNode(12);
	CLL.printList();
 
	CLL.removeNode(7);
	CLL.printList();
 
	CycleLinkedList CLL2;
	CLL2.appendHead(2);
	CLL2.appendHead(1);
	CLL2.removeNode(1);
	CLL2.printList();
 
	CycleLinkedList CLL3;
	CLL3.appendHead(1);
	CLL3.printList();
 
	CLL3.insertNode(0, 3);
	CLL3.insertNode(0, 2); 
	CLL3.insertNode(0, 1);
	CLL3.insertNode(3, 3);
	CLL3.insertNode(4, 2);
	CLL3.insertNode(5, 1);
	CLL3.printList();
 
	CycleLinkedList CLL4;
	CLL4.insertNode(0,1);
	CLL4.insertNode(1,2);
	CLL4.insertNode(1, 3);
	CLL4.insertNode(3, 4);
	CLL4.printList();
 
	CLL.clearList();
	CLL.printList();

    return 0;
}
