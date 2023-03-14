#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
	int dato;
	struct Nodo *izquierda;
	struct Nodo *derecha;
};

struct Nodo *nuevoNodo(int dato)
{
	size_t tamaNodo = sizeof(struct Nodo);
	struct Nodo *nodo = (struct Nodo*)malloc(tamaNodo);
	nodo->dato = dato;
	nodo->izquierda = nodo->derecha = NULL;
	
	return nodo;
}

void insertarNodo(struct Nodo *nodo, int dato);
void imprimirBFS(struct Nodo *nodo, int nivel);
void cicloBFS(struct Nodo *nodo);

int puntoFinal;
int indicador = 0;

using namespace std;

int main()
{
	struct Nodo *nodoRaiz = nuevoNodo(344);
	insertarNodo(nodoRaiz, 140);
	insertarNodo(nodoRaiz, 350);
	insertarNodo(nodoRaiz, 100);
	insertarNodo(nodoRaiz, 270);
	insertarNodo(nodoRaiz, 348);
	insertarNodo(nodoRaiz, 420);
	insertarNodo(nodoRaiz, 50);
    insertarNodo(nodoRaiz, 140);
    insertarNodo(nodoRaiz, 182);
	insertarNodo(nodoRaiz, 307);
	insertarNodo(nodoRaiz, 402);
	insertarNodo(nodoRaiz, 430);
	insertarNodo(nodoRaiz, 10);
	insertarNodo(nodoRaiz, 54);
	insertarNodo(nodoRaiz, 138);
	insertarNodo(nodoRaiz, 181);
    insertarNodo(nodoRaiz, 189);
    insertarNodo(nodoRaiz, 300);
	insertarNodo(nodoRaiz, 310);
	insertarNodo(nodoRaiz, 356);
	insertarNodo(nodoRaiz, 410);
	insertarNodo(nodoRaiz, 440);
	insertarNodo(nodoRaiz, 55);
	insertarNodo(nodoRaiz, 130);
	insertarNodo(nodoRaiz, 190);
    insertarNodo(nodoRaiz, 298);
    insertarNodo(nodoRaiz, 302);
	insertarNodo(nodoRaiz, 408);
    insertarNodo(nodoRaiz, 450);

	cout<<"54    138   181    |     |     |     |     |  \n";
	cout<<"10     |    189    |     |     |     |     |  \n";
	cout<<"430    |    300   310   356   410   440    |  \n";
	cout<<"402    |     |     |     |     |    55     |  \n";
	cout<<"307    |     |     |     |     |    130    |  \n";
	cout<<"182    |    450   408   302   298   190    |  \n";
	cout<<"140    |     |     |     |     |     |     |  \n";
	cout<<"50    420   348   270   100   350   140   344  \n";

	cout<<"\nPunto actual: 344. A donde desea ir?: ";
	cin>>puntoFinal;

	cicloBFS(nodoRaiz);

	if(indicador == 1)
		cout<<"\nMeta alcanzada";
	else	
		cout<<"\nNo se encuentra el punto deseado..";

	return 0;
}

void insertarNodo(struct Nodo *nodo, int dato)
{
	if(dato > nodo->dato)
    {			
		if(nodo->derecha == NULL)
			nodo->derecha = nuevoNodo(dato);	   		
		else
			insertarNodo(nodo->derecha, dato);
	}	
	else
    {								
		if(nodo->izquierda == NULL)
			nodo->izquierda = nuevoNodo(dato);
		else
			insertarNodo(nodo->izquierda, dato);
	}
}

int alturaBFS(struct Nodo *nodo)
{ 
    if(nodo == NULL)
        return 0;
    else
    {
        int alturaIzq = alturaBFS(nodo->izquierda);
        int alturaDer = alturaBFS(nodo->derecha);

        if (alturaIzq > alturaDer)
            return (alturaIzq+1);
        else
            return (alturaDer+1);
    }
}

void cicloBFS(struct Nodo *nodo)
{
    int h = alturaBFS(nodo);
    int i;

	std::cout<<"Usted esta en: ";

    for(i = 1; i <= h; i++)
        imprimirBFS(nodo, i);
}
 
void imprimirBFS(struct Nodo *nodo, int nivel)
{
    if(nodo == NULL)
		return;

	if(nivel == 1)
    {
		if(indicador == 0)
        {
			std::cout<<"<<"<<nodo->dato<<">>";
			
			if(nodo->dato == puntoFinal)
				indicador = 1;
			else
				std::cout<<" ~ ";
		}
	}
	else if(nivel > 1)
    {
			imprimirBFS(nodo->izquierda, nivel-1);
			imprimirBFS(nodo->derecha, nivel-1);
	}
}