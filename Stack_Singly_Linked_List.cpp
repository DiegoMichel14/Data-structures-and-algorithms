//Implementation of stack using singly linked list
//Diego Alejandro Michel Castro

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

//Declaration of the structure
struct Node {  //Structure for the node to use in the list
	int data;
	struct Node* link;
} *top = NULL ;  // Global pointer to the first node of the linked list with type struct node

//Function to check if the stack is empty
int isEmpty(){
	if(top == NULL)
		return 1;
	else
		return 0;
};

//Push operation to add a new node at the beggining of the list
void push(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*)); 
	if(newNode == NULL){     //Malloc returns a NULL value when the requested memory can't be used
		cout << "\n" << "Stack overflow" << endl;
		exit(1);
	};
	newNode -> data = data;
	newNode -> link = NULL;

	newNode -> link = top;
	top = newNode;
};

//Function to pop an element of the stack
int pop(){
	struct Node* temp;
	int value;
	if(isEmpty()){
		printf("Stack underflow");  //Empty stack to work with
		exit(1);
	};

	temp = top;
	value = temp -> data;
	top = top -> link;
	free(temp);
	temp = NULL;
	return value;
};

//Function to check the peek of the stack
int peek(){
	if(isEmpty()){
		printf("Empty list");
		exit(1);
	};
	return top -> data;
};

//Function to print the full list with the stack implementation
void display(){
	struct Node* temp; //Creation of a temporal pointer, to assing the adress of the first node to temp
	temp = top;

	if(isEmpty()){
		printf("Empty list");
		exit(1);
	};

	printf("The elements of the list are: ");
	while(temp){  //Loop to print all the elements in the length of temp and while temp is not = to NULL
		printf("%d ", temp -> data);
		temp = temp -> link;
	}
	printf("\n");
};

//Function for the program interface
void interface(){
	int option, data;
	while(1){   //Infitine loop for the user until an option selection
		printf("Select option to do with the list \n");
		printf("1.) Push an element \n");
		printf("2.) Pop an element \n");
		printf("3.) Display top element \n");
		printf("4.) Print the list \n");
		printf("5.) Exit program \n");
		scanf("%d", &option);
	

		switch(option){
			case 1:
				printf("Element to insert in the list: ");
				scanf("%d", &data);
				push(data);
				break;


			case 2:
				data = pop();
				printf("Element popped is %d \n", data);
				break;

			case 3: 
				printf("The top element of the stack is %d \n", data);
				break;

			case 4: display(); break;
			case 5:
				exit(1);

			default:
				cout << "Invalid option " << endl;
				break;
		};
	};
};


int main(){

	interface();

	return 0;
};