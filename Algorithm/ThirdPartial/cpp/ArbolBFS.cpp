#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Nodo{
	int dato;
	struct Nodo *izq;
	struct Nodo *der;
};

struct Nodo *nuevoNodo(int dato){
	size_t tamaNodo = sizeof(struct Nodo);
	struct Nodo *nodo = (struct Nodo*)malloc(tamaNodo);
	nodo->dato = dato;
	nodo->izq = nodo->der = NULL;
	
	return nodo;
}

void insertar(struct Nodo *nodo, int dato);
void preorden(struct Nodo *nodo);
void inorden(struct Nodo *nodo);
void postorden(struct Nodo *nodo);
int vacio(struct Nodo *nodo);
int buscar(struct Nodo *nodo, int dato);
void iBFS(struct Nodo *nodo, int nivel);
void cBFS(struct Nodo *nodo);

using namespace std;

int main(){
	struct Nodo *raiz = nuevoNodo(28);
	insertar(raiz, 11);
	insertar(raiz, 96);
	insertar(raiz, 21);
	insertar(raiz, 6);
	insertar(raiz, 97);
	insertar(raiz, 1);
	insertar(raiz, 30);
    insertar(raiz, 10);
    insertar(raiz, 2);
    
	cout<<"\n Preorden\n";
    preorden(raiz);
    
	cout<<"\n Inorden\n";
    inorden(raiz);
    
	cout<<"\n Postorden\n";
    postorden(raiz);

	cout<<"\n Orden BFS del arbol es:\n";
	cBFS(raiz);

	return 0;
}

void insertar(struct Nodo *nodo, int dato){
	if(dato > nodo->dato){			
		if(nodo->der == NULL)
			nodo->der = nuevoNodo(dato);	   		
		else
			insertar(nodo->der, dato);
	}	
	else{								
		if(nodo->izq == NULL)
			nodo->izq = nuevoNodo(dato);
		else
			insertar(nodo->izq, dato);
	}
}
	
void preorden(struct Nodo *nodo){
	if(nodo != NULL){
		std::cout<<nodo->dato<<" ";
		preorden(nodo->izq);
		preorden(nodo->der);
	}
}

void inorden(struct Nodo *nodo){
	if(nodo != NULL){
		inorden(nodo->izq);
		std::cout<<nodo->dato<<" ";
		inorden(nodo->der);
	}
}

void postorden(struct Nodo *nodo){
	if(nodo != NULL){
		postorden(nodo->izq);
		postorden(nodo->der);
		std::cout<<nodo->dato<<" ";
	}
}

int vacio(struct Nodo *nodo){
   return nodo == NULL;
}

int buscar(struct Nodo *nodo, int dato){
	struct Nodo *nodoActual = nodo;

	while(!vacio(nodoActual)) {
		if(dato == nodoActual->dato)
			return nodoActual->dato;
		else if(dato < nodoActual->dato) 
			nodoActual = nodoActual->izq;
		else if(dato > nodoActual->dato) 
			nodoActual = nodoActual->der;
	}

	return -1;
}

int aBFS(struct Nodo *nodo){ 
    if(nodo == NULL)
        return 0;
    else{
        int iAltura = aBFS(nodo->izq);
        int dAltura = aBFS(nodo->der);

        if (iAltura > dAltura)
            return (iAltura+1);
        else
            return (dAltura+1);
    }
}

void cBFS(struct Nodo *nodo){
    int h = aBFS(nodo);
    int i;
    for(i = 1; i <= h; i++)
        iBFS(nodo, i);
}
 
void iBFS(struct Nodo *nodo, int nivel){
    if (nodo == NULL)
        return;
    if(nivel == 1)
		std::cout<<nodo->dato<<" ";
    else if(nivel > 1){
        iBFS(nodo->izq, nivel-1);
        iBFS(nodo->der, nivel-1);
    }
}