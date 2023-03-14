#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *newNode(int data){
	size_t nodeSize = sizeof(struct Node);
	struct Node *node = (struct Node*)malloc(nodeSize);
	node->data = data;
	node->left = node->right = NULL;
	
	return node;
}

void push(struct Node *node, int data);
void newTree();
void printMaze();
void moveInMaze();
void printBFS(struct Node *node, int level);
void loopBFS(struct Node *node);

struct Node *root = newNode(96);

int obj; int stepsCount = 0; int flag = 0;

using namespace std;

int main(){ newTree(); printMaze(); moveInMaze(); return 0; }

void newTree(){
    push(root, 81);     push(root, 210);    push(root, 79);
	push(root, 87);     push(root, 188);    push(root, 309);    
    push(root, 78);     push(root, 170);    push(root, 190);
	push(root, 300);    push(root, 510);    push(root, 50);     
    push(root, 160);    push(root, 189);    push(root, 303);
    push(root, 900);    push(root, 49);     push(root, 63);     
    push(root, 165);    push(root, 302);    push(root, 601);
	push(root, 999);    push(root, 15);     push(root, 51);  
    push(root, 68);     push(root, 301);    push(root, 703);
    push(root, 2);      push(root, 16);     push(root, 52);     
    push(root, 65);
}

void printMaze(){
    cout<<"      ~ProyectoLaberinto~     \n\n";

    cout<<"78  170 190  #   68 301 703  #  \n";
	cout<<"309  #  300  #   51  #   2   16 \n";
	cout<<"188  #  510  #   15  #   #   52 \n";
	cout<<"87   #  50   #   999 #   #   65 \n";
	cout<<"79   #  160  #   601 #   #   #  \n";
	cout<<"210  #  189  #   302 #   #   #  \n";
	cout<<"81   #  303  #   165 #   #   #  \n";
	cout<<"96   #  900  49  63  #   #   #  \n";
}

void moveInMaze(){
    cout<<"\nPunto de inicio 96, favor de elegir punto de llegada: ";
	cin>>obj;

	loopBFS(root);

	if(flag == 1)
		cout<<"\nObjetivo encontrado con exito!";
	else	
		cout<<"\nEl objetivo no se ha encontrado!";
}

void push(struct Node *node, int data){
	if(data > node->data){			
		if(node->right == NULL)
			node->right = newNode(data);	   		
		else
			push(node->right, data);
	}	
	else{								
		if(node->left == NULL)
			node->left = newNode(data);
		else
			push(node->left, data);
	}
}

int heightBFS(struct Node *node){ 
    if(node == NULL)
        return 0;
    else{
        int leftHeight = heightBFS(node->left);
        int rightHeight = heightBFS(node->right);

        if (leftHeight > rightHeight)
            return (leftHeight+1);
        else
            return (rightHeight+1);
    }
}

void loopBFS(struct Node *node){
    int j = heightBFS(node);
    int i = 1;

	std::cout<<"Punto inicial:\n";

    for(; i<=j; i++)
        printBFS(node, i);
}
 
void printBFS(struct Node *node, int level){
    if(node == NULL)
		return;

	if(level == 1){
		if(flag == 0){
            if(stepsCount == 0)
                std::cout<<" => ";

            stepsCount++;
			std::cout<<"["<<node->data<<", movimiento: "<<stepsCount<<"]\n";
			
			if(node->data == obj)
				flag = 1;
			else
				std::cout<<" => ";
		}
	}
	else if(level > 1){
			printBFS(node->left, level-1);
			printBFS(node->right, level-1);
	}
}