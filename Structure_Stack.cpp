#include <iostream>
#include <cstdlib>

using namespace std;


#define SIZE 10

//Class for a Stack
class Stack{

    //Properties
    int *arr;
    int top;
    int capacity;

    //Declare methods
    public:
        Stack(int size=SIZE);
        void push(int);
        int pop();
        int peek();
        bool isEmpty();
        bool isFull();
        int size();

};

//Method definitions
Stack::Stack(int size){  //Constructor para el elemento Stack
    arr = new int[size];
    capacity = size;
    top = -1; //Si no hay ningún elemento el top está en -1, una función inválida
};

void Stack::push(int x){  //Constructor para el elemento push
    //Validate isFull()
    if(isFull()){
        exit(EXIT_FAILURE);
    };

    cout << "Inserted: " << x << endl;

    //arr[top + 1] = x;
    arr[++top] = x;
};

bool Stack::isFull(){
    // return size() == capacity;
    return top == capacity -1;
};

int Stack::pop(){
    
    // Validate isEmpty()
    if(isEmpty()){
        exit(EXIT_FAILURE);
    };

    // To Do
    cout << "Popped: " << peek() << endl;
    return arr[top--];
};

int Stack::peek(){

    if(isEmpty()){
        exit(EXIT_FAILURE);
    }

    return arr[top];
}

bool Stack::isEmpty(){
    return top == -1;
}

int Stack::size(){
    return top + 1;
}

int main(){

    cout << "Hello! Stack\n" << endl;

    Stack stack(5);

    // push
    stack.push(2);  //Cargamos valores al stack
    stack.push(6);  //Cargamos valores al stack

    stack.pop();    //Borramos los valores ingresados
    stack.pop();

    stack.push(3); //Cargamos valor al stack

    cout << "The top is: " << stack.peek() << endl;

    stack.pop();  //Si queremos eliminar algún elemento pero se encuentra vacío el stack
    stack.pop();  //simplemente sale del programa, por eso no imprime nada

    return 0;
}