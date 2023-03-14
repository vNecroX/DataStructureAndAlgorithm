#include <stdio.h>
#include <stdlib.h>

struct Nodo{
	int dato;
	struct Nodo *izq;
	struct Nodo *der;
};

struct Nodo *nuevonodo(int dato){
	  //se pide el espacio en memoria para el nuevo nodo
	size_t tamaNodo = sizeof(struct Nodo);
	struct Nodo *nodo = (struct Nodo*)malloc(tamaNodo);
		// Asignar el dato al iniciar
	nodo->dato = dato;
	nodo->izq = nodo->der = NULL;
	
	return nodo;
}

struct Nodo *buscar(struct Nodo *raiz, int d){
	if(raiz->dato == d){
		printf("Nodo con valor: %i ha sido encontrado!", d);
		return raiz;
	} 
	else if(d > raiz->dato) 
		return buscar(raiz->der, d);
	else 
		return buscar(raiz->izq, d);
}

void insertar(struct Nodo *nodo, int dato){
	if(dato > nodo->dato){				//si es mayor va a la derecha
		if(nodo->der == NULL)
			nodo->der = nuevonodo(dato);	   		
		else
			insertar(nodo->der, dato);
	}	
	else{								// sino a la izquiera
		if(nodo->izq == NULL)
			nodo->izq = nuevonodo(dato);
		else
			insertar(nodo->izq, dato);
	}
}
	
void preorden(struct Nodo *nodo){
	if(nodo != NULL){
		printf("%d ", nodo->dato);
		preorden(nodo->izq);
		preorden(nodo->der);
	}
}

void inorden(struct Nodo *nodo){
	if(nodo != NULL){
		inorden(nodo->izq);
		printf("%d ", nodo->dato);
		inorden(nodo->der);
	}
}

void postorden(struct Nodo *nodo){
	if(nodo != NULL){
		postorden(nodo->izq);
		postorden(nodo->der);
		printf("%d ", nodo->dato);
	}
}

int main(){
	struct Nodo *raiz = nuevonodo(28);
	insertar(raiz, 11);
	insertar(raiz, 96);
	insertar(raiz, 21);
	insertar(raiz, 6);
	insertar(raiz, 97);
	insertar(raiz, 1);
	insertar(raiz, 30);
    insertar(raiz, 10);
    insertar(raiz, 2);
    
    printf("\n Preorden\n");
    preorden(raiz);
    
    printf("\n Inorden\n");
    inorden(raiz);
    
    printf("\n Postorden\n");
    postorden(raiz);

	printf("\n Buscar nodo: 1\n");
	raiz = buscar(raiz, 1);

	return 0;
}