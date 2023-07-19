//Implementación de estructura de datos no lineales, Binary Search Tree
//Última modificación 15/07/2023
//Diego Alejandro Michel Castro | A01641907

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

struct Node{      //Node structor declaration
    int data;
    Node *left, *right;

    Node(int d):data(d), left(NULL), right(NULL){}
};

class BST{
    private:
        Node *Root;

        void Insert(int&, Node*&);      //Private Methods
        void InOrder(Node*);
        void PreOrder(Node*);
        void PostOrder(Node*);
        void DeleteNode(int&, Node*&);

    public:
        BST():Root(NULL){}
        ~BST(){
            DeleteBST(Root);
            cout << "\nDestructor: BST deleted.\n";
        }

        void Insert(int &value) { Insert(value, Root);}    //Public methods

        void InOrder() {InOrder(Root);}
        void PreOrder() {PreOrder(Root);}
        void PostOrder() {PostOrder(Root);}
        void BFT();     //Print by level order

        void SubstituteToMin(Node*&, Node*&);
        void DeleteNode(int &value) {DeleteNode(value, Root);}

        void DeleteBST(Node*&);
};


void BST::Insert(int &value, Node *&currentNode){ //*& Receive pointer by reference, int*& is a reference to a pointer
    if(currentNode == NULL){                      //to an int
        currentNode = new Node(value);
    }
    else{
        if(value < currentNode -> data)
            Insert(value, currentNode -> left);
        else if(value > currentNode -> data)
            Insert(value, currentNode -> right);
        else
            cout << "Repeated element \n";
    }
};


void BST::InOrder(Node *currentNode){
    if(currentNode == NULL)
        return;
    
    InOrder(currentNode -> left);
    cout << currentNode -> data << " -> ";
    InOrder(currentNode -> right);    

};


void BST::PreOrder(Node *currentNode){
    if(currentNode == NULL)
        return;
    
    cout << currentNode -> data << " -> ";
    PreOrder(currentNode -> left);
    PreOrder(currentNode -> right);
};

void BST::PostOrder(Node *currentNode){
    if(currentNode == NULL)
        return;
    
    PostOrder(currentNode -> left);
    PostOrder(currentNode -> right);
    cout << currentNode -> data << " -> ";
};

void BST::BFT(){
    if(Root == NULL){
        cout << "The BST is empty " << endl;
        return;
    }

    queue<Node*> Q;
    Q.push(Root);

    Node *Aux;
    while(!Q.empty()){
        Q.push(NULL);

        Aux = Q.front();
        while(Aux != NULL){
            cout << Aux -> data << " ";

            if(Aux -> left != NULL)
                Q.push(Aux -> left);
            if(Aux -> right != NULL)
                Q.push(Aux -> right);

            Q.pop();
            Aux = Q.front();
        }
        Q.pop();
        
        cout << endl;
    }
};


void BST::SubstituteToMin(Node *&aptAux, Node *&aptNode){
    if(aptAux -> left != NULL)  //aptNode is the node to be deleted and aptAux the MinValue
        SubstituteToMin(aptAux -> left, aptNode);
    else{
        aptNode -> data = aptAux -> data; //Transfer data from the substitude Node
        aptNode = aptAux;  //Save the minValue Node to delete
        aptAux= aptAux -> right;  //Swapp place node or null for minValue to right
    }
};


void BST::DeleteNode(int &value, Node *&currentNode){
    if(currentNode == NULL){
        cout << " The BST is empty " << endl << endl;
    }
    else{
        if(value < currentNode -> data)
            DeleteNode(value, currentNode -> left);
        else if(value > currentNode -> data)
            DeleteNode(value, currentNode -> right);
        else{
            Node *apAux = currentNode;

            if(apAux -> right == NULL)  //left leaf node
                currentNode = apAux -> left;
            if(apAux -> left == NULL)  //right leaf node
                currentNode = apAux -> right;
            if(apAux -> left != NULL && apAux -> right != NULL) //two child nodes
                SubstituteToMin(currentNode -> right, apAux);

            cout << "\nKey to delete is: " << value << endl;
            cout << "The element was delete with the key: " << apAux -> data << endl;
            delete apAux;
        };    
    };
};


void BST::DeleteBST(Node *&currentNode){
    if(!currentNode)  //Travel BST in Post-Order Traversal
        return;
    
    DeleteBST(currentNode -> left);
    DeleteBST(currentNode -> right);
    delete currentNode;
};


int main(){
    system("cls");

    BST A;

    vector<int> v={47,60,22,12,6,13,41,20,52,16};
    for(int i : v){
        A.Insert(i);
    }

    cout << "In order: ";
    A.InOrder();
    cout << "\nPre-Order: ";
    A.PreOrder();
    cout << "\nPost-Order: ";
    A.PostOrder();
    cout << "\nLevel-Order Traversal: " << endl;
    A.BFT();

    int a = 16; //Leaf node
    A.DeleteNode(a);
    A.BFT();

    a = 13; //Only one child node
    A.DeleteNode(a);
    A.BFT();

    a = 47; //Two child nodes (Root)
    A.DeleteNode(a);
    A.BFT();

    return 0;
};