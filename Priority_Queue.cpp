#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Node{   //Creation of the structure to use in the list, Complexity O(1)
    int priority;         //Data type to store in the nodes
    int data;          
    struct Node *next;
};

class PriorityQueue{ //Complexity O(1)
    private:
        Node *f;  //Create ponter f with node structure

    public:
        PriorityQueue():f(NULL){}
        ~PriorityQueue(){
            cout << "Destructor: ";
        delete f;
    }

    Node* read(int);  //Methods for the class use
    void Delete(int);
    void update(int,int);
    void create(int,int);
    void display();
    void del();
};

Node* PriorityQueue::read(int value){   //Complexity O(n)
    Node *aptNode = this ->f;

    while(aptNode != NULL && aptNode ->data != value){
        aptNode = aptNode->next;   //Travel the list to find the value entered
    }                      

    if(aptNode == NULL){
        cout <<"Item not found"<< endl;    //Exit messege for not valid item
    }

    return aptNode;
}

void PriorityQueue::Delete(int value){  //Complexity O(1)
    Node *aptNode = this ->f;   //Assing to pointer f of the node structure
    
    if(f == aptNode){
        f = aptNode->next;      //Remove elements if valid stored in the list
    }
    if(aptNode == NULL){
        cout << "item not found" << endl;  //Exit messege for not valid item
        return;
    }

    while(aptNode -> data != value){        
    }    
};

void PriorityQueue::update(int dat, int newDat){ //Complexity O(1)
    Node *aptNode = read(dat);  //Method call to validate if the value to update is in the list

    if(aptNode == NULL){
        cout <<"item not found"<<endl;  //Exit method for unexistant  value 
        return;
    }

    aptNode -> data = newDat;  //Assing the data to the new variable
};

void PriorityQueue::create(int i,int priority){  //Complexity O(n)
    Node *t, *q;
    t = new Node;
    t->data = i;
    t->priority = priority;   //Insertion sort method to sort the elements based on the priorrity value
    if (f == NULL || priority < f->priority) {
        t->next= f;
        f = t;
    } else {
        q = f;
        while (q->next != NULL && q->next->priority <= priority)
            q = q->next;    //Use of the pointers t,q and next for the insertion on the correct place
            t->next = q->next;
            q->next = t;
    }    
};


void PriorityQueue::display(){   //Complexity O(n)
    Node *ptr;
    ptr = f;
    if (f == NULL)
        cout<<"Empty list\n";  //Exit messege if the list doesn't have nodes created
    else {
        cout << "Queue is :\n" << endl; 
        cout << "Priority Value -> \n" << endl;
        while(ptr != NULL) {
            cout << ptr -> priority << " " << ptr -> data <<endl;  //Return validation if item is found on the list
            ptr = ptr->next;   //Temp pointer assignation to next
        }
    }
};

void PriorityQueue::del(){   //Complexity O(1)
    Node *t;
    if(f == NULL) //if queue is null
        cout<<" Invalid Queue\n";  //Exit messege if pointer = Null
    else {
        t = f;
        cout << "Deleted item is: " << t -> data <<endl;
        f = f -> next;
        free(t);     //Free function will release the values that has no use for that are stored in memory
    }
};

// fucnion para desplegar el menu de acciones
void interface(PriorityQueue list){
    int input, state = 0, prevElement, prio;

while(state == 0){    //Initial menu for the operations for the Queue on list
    cout << "1.) Insert an element on the list " << endl;
    cout << "2.) Remove an element of the list " << endl;
    cout << "3.) Print list "<<endl;
    cout << "4.) Update element "<<endl;
    cout << "5.) Search element "<<endl;
    cout << "6.) Delete list "<<endl;
    cin >> state;
    

if (state== 1){  //Create a new node with data to store
    cout << "Value to insert " << endl ;
    cin >> input;
    cout << "Priority of the value: " << endl;
    cin >> prio;
    list.create(input,prio);
    list.display();
    cout << "0.) Return to interface " << endl;
     
    cin>>state;

}

     
if(state == 2){   //Remove elements
    cout << "Element to delete: " << endl;
    cin >> input;
    list.Delete(input);
    list.display();
    cout << "0.) Return to interface" << endl;
    cin >> state;
}
    

if(state == 3){   //Display list with prio values
    cout << "Print list " << endl;
    list.display();
    cout << "0.) Return to interface " << endl;
    cin >> state;
}


if(state ==4){       //Change an item on the list
    cout << "Value to update "<<endl;
    cin >> prevElement;
    cout << "Value to change "<<endl;
    cin >> input;
    list.update(prevElement,input);
    list.display();
    cout << "0.) Return to interface " << endl;
     
    cin>>state;
}

if(state == 5){   //Search a value on the list
    cout << "Value to search: " << endl;
    cin >> input;
    list.read(input);
    cout << "List contains element " << list.read(input)->data << endl;
    list.display();
    cout << "0.) Return to interface " << endl;
    cin >> state;
}


if(state == 6){   //List erased
    cout << "List deleted " << endl;
    list.del();
    cout << "0.) Return to interface " << endl;
    list.display();
    cin>>state;
}

else{
    cout << " " << endl;
}

    }
}


int main(){
    PriorityQueue sample;  //Object of PriorityQueue class
    interface(sample);

    return 0;
};