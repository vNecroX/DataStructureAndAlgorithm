#include <iostream>

class Node{
    public:
        int data;
	    Node *leftNode;
	    Node *rightNode;
};

Node *newNode(int d){
    Node *nNode;
    nNode->data = d;
    nNode->leftNode = nNode->rightNode = NULL;
    return nNode;
}

void push(Node *node, int d){
    if(d > node->data){     //si es mayor va a la derecha
        if(node->rightNode == NULL)
            node->rightNode = newNode(d);                            
        else
            push(node->rightNode, d);
    }	
    else{                   // sino a la izquiera
        if(node->leftNode == NULL)
            node->leftNode = newNode(d);
        else
            push(node->leftNode, d);
    }
}

void pre(Node *node){
    if(node != NULL){
        std::cout<<" "<<node->data;
        pre(node->leftNode);
        pre(node->rightNode);
    }
}

void in(Node *node){
     if(node != NULL){
        in(node->leftNode);
        std::cout<<" "<<node->data;
        in(node->rightNode);
    }
}

void post(Node *node){
    if(node != NULL){
        post(node->leftNode);
        post(node->rightNode);
        std::cout<<" "<<node->data;
    }
}

/*
struct Nodo *nuevonodo(int data){
	  //se pide el espacio en memoria para el nuevo nodo
	size_t tamaNodo=sizeof(struct Nodo);
	struct Nodo *nodo=(struct Nodo *)malloc(tamaNodo);
		// Asignar el data al iniciar
	nodo->data=data;
	nodo->leftNode=nodo->rightNode=NULL;
	
	return nodo;
	
}
*/
/*
	void push(struct Nodo *nodo,int d);
	void preorden(struct Nodo *nodo);
	void inorden(struct Nodo *nodo);
	void postorden(struct Nodo *nodo);
	
    */

using namespace std;

int main(){
    Node *root = newNode(28);
	push(root, 11);
	push(root, 96);
	push(root, 21);
	push(root, 6);
	push(root, 97);
	push(root, 1);
	push(root, 30);
    push(root, 10);
    push(root, 2);
    
    cout<<"\n Preorden\n";
    pre(root);
    
    cout<<"\n Inorden\n";
    in(root);
    
    cout<<"\n Postorden\n";
    post(root);

	return 0;
}